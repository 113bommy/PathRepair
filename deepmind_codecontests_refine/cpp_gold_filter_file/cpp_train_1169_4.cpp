#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
  bool done_something = false;
  stringstream res;
  res << "[";
  for (; begin_iter != end_iter and counter; ++begin_iter) {
    done_something = true;
    counter--;
    res << *begin_iter << ", ";
  }
  string str = res.str();
  if (done_something) {
    str.pop_back();
    str.pop_back();
  }
  str += "]";
  return str;
}
vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
  vector<int> ord(size);
  for (int i = 0; i < size; i++) ord[i] = i;
  sort(ord.begin(), ord.end(), compare);
  return ord;
}
template <typename T>
bool MinPlace(T& a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool MaxPlace(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T>& p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    out << v[i];
    if (i != (int)v.size() - 1) out << ", ";
  }
  out << "]";
  return out;
}
template <class TH>
void _dbg(const char* name, TH val) {
  clog << name << ": " << val << endl;
}
template <class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
  while (*names != ',') clog << *names++;
  clog << ": " << curr_val << ", ";
  _dbg(names + 1, vals...);
}
long long pow(long long x, long long e, long long mod) {
  long long res = 1;
  for (; e >= 1; e >>= 1) {
    if (e & 1) res = res * x % mod;
    x = x * x % mod;
  }
  return res;
}
int k = 0;
long long pot[100];
long long val[100];
const long long mod = 998244353;
void add(long long x) {
  for (int i = 0; i < k; i++) {
    if (pot[i] & x) x ^= val[i];
  }
  if (x != 0) {
    pot[k] = 1;
    val[k] = x;
    while ((pot[k] & x) == 0) pot[k] <<= 1;
    k++;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    long long x;
    cin >> x;
    add(x);
  }
  if (k <= 21) {
    vector<long long> poss = {0};
    for (int i = 0; i < k; i++) {
      int q = poss.size();
      for (int j = 0; j < q; j++) poss.push_back(poss[j] ^ val[i]);
    }
    vector<long long> res(M + 1, 0);
    for (long long x : poss) res[__builtin_popcountll(x)]++;
    for (int i = 0; i <= M; i++)
      cout << res[i] * pow(2, N - k, mod) % mod << " ";
    cout << "\n";
  } else {
    for (int i = 0; i < k; i++)
      for (int j = 0; j < i; j++) {
        if (val[j] & pot[i]) val[j] ^= val[i];
      }
    vector<int> suff(k, 0);
    long long mm = 0;
    for (int i = 0; i < k; i++) mm ^= pot[i];
    for (int i = 0; i < k; i++) {
      int cnt = 0;
      for (int j = 0; j < M; j++) {
        if ((mm & (1ll << j)) == 0) {
          if (val[i] & (1ll << j)) suff[i] ^= 1 << cnt;
          cnt++;
        }
      }
    }
    vector<vector<long long>> poss(k + 1, vector<long long>(1 << (M - k), 0));
    poss[0][0] = 1;
    for (int i = 0; i < k; i++) {
      for (int s = i; s >= 0; s--) {
        for (int x = 0; x < (1 << (M - k)); x++) {
          poss[s + 1][x ^ suff[i]] =
              (poss[s + 1][x ^ suff[i]] + poss[s][x]) % mod;
        }
      }
    }
    vector<long long> res(M + 1);
    for (int s = 0; s <= k; s++) {
      for (int x = 0; x < (1 << (M - k)); x++) {
        int z = s + __builtin_popcountll(x);
        res[z] = (res[z] + poss[s][x]) % mod;
      }
    }
    for (int i = 0; i <= M; i++)
      cout << res[i] * pow(2, N - k, mod) % mod << " ";
    cout << "\n";
  }
}
