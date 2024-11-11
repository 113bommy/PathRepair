#include <bits/stdc++.h>
using namespace std;
vector<int> ds;
vector<vector<pair<int, int> > > es;
vector<bool> bolo;
vector<pair<int, int> > dynamic_minu_ones;
vector<int> pocet_hran;
vector<int> to_remove;
int n, m;
bool da_sa = true;
long long PRIME = 1e9 + 7;
long long fakt[1000000 + 7];
long long inv_a[1000000 + 7];
long long seed, op, l, r, x, y, vmax;
long long rnd() {
  long long ret = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return ret;
}
void generate_cmd() {
  op = (rnd() % 4) + 1;
  l = (rnd() % n) + 1;
  r = (rnd() % n) + 1;
  if (l > r) swap(l, r);
  if (op == 3)
    x = (rnd() % (r - l + 1)) + 1;
  else
    x = (rnd() % vmax) + 1;
  if (op == 4) y = (rnd() % vmax) + 1;
}
struct Entry {
  long long pos;
  long long val;
};
bool operator<(const Entry& x, const Entry& y) {
  return std::tie(x.pos, x.val) < std::tie(y.pos, y.val);
}
set<Entry>::iterator find_iterator(long long pos, set<Entry>& arr) {
  Entry en = {pos, 0};
  auto it = arr.lower_bound(en);
  if (it->pos > pos) {
    it--;
    auto it_val = *it;
    Entry en = {pos, it_val.val};
    it = arr.insert(en).first;
  }
  return it;
}
long long power(long long x, long long m, long long prv) {
  long long res = 1;
  long long moc = x;
  moc %= prv;
  while (m) {
    if (m % 2 == 1) {
      res *= moc;
      res %= prv;
    }
    moc *= moc;
    moc %= prv;
    m /= 2;
  }
  return res;
}
int main() {
  cin >> n >> m >> seed >> vmax;
  set<Entry> arr;
  for (long long i = 1; i <= n; i++) {
    Entry en = {i, (rnd() % vmax) + 1};
    arr.insert(en);
  }
  Entry en = {n + 1, -1};
  arr.insert(en);
  for (int i = 0; i < (m); i++) {
    generate_cmd();
    auto it_l = find_iterator(l, arr);
    auto it_r = find_iterator(r + 1, arr);
    auto it_c = it_l;
    if (op == 1) {
      while (it_l != it_r) {
        it_c++;
        auto it_val = *it_l;
        arr.erase(it_l);
        Entry en = {it_val.pos, it_val.val + x};
        arr.insert(en);
        it_l = it_c;
      }
    } else if (op == 2) {
      while (it_l != it_r) {
        it_c++;
        arr.erase(it_l);
        it_l = it_c;
      }
      Entry en = {l, x};
      arr.insert(en);
    } else if (op == 3) {
      multiset<pair<long long, long long> > mn;
      while (it_l != it_r) {
        it_c++;
        mn.insert(make_pair(it_l->val, it_c->pos - it_l->pos));
        it_l = it_c;
      }
      for (auto p : mn) {
        if (x <= p.second) {
          cout << p.first << endl;
          break;
        }
        x -= p.second;
      }
    } else if (op == 4) {
      do {
        if (0)
          std::cerr << "op4"
                    << " ";
      } while (0);
      long long res = 0;
      do {
        if (0)
          std::cerr << "l"
                    << ": " << l << std::endl;
      } while (0);
      do {
        if (0)
          std::cerr << "r"
                    << ": " << r << std::endl;
      } while (0);
      do {
        if (0)
          std::cerr << "x"
                    << ": " << x << std::endl;
      } while (0);
      do {
        if (0)
          std::cerr << "y"
                    << ": " << y << std::endl;
      } while (0);
      do {
        if (0)
          std::cerr << "x"
                    << ": " << x << std::endl;
      } while (0);
      while (it_l != it_r) {
        it_c++;
        do {
          if (0)
            std::cerr << "it_c->pos"
                      << ": " << it_c->pos << std::endl;
        } while (0);
        do {
          if (0)
            std::cerr << "it_l->pos"
                      << ": " << it_l->pos << std::endl;
        } while (0);
        do {
          if (0)
            std::cerr << "it_c->pos - it_l->pos"
                      << ": " << it_c->pos - it_l->pos << std::endl;
        } while (0);
        res += ((it_c->pos - it_l->pos) * power(it_l->val, x, y)) % y;
        res %= y;
        it_l = it_c;
      }
      cout << res << endl;
    }
  }
}
