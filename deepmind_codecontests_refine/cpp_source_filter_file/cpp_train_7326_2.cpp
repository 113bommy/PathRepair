#include <bits/stdc++.h>
using namespace std;
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... s) {
  long long idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ", ";
  dbs(str.substr(idx + 1), s...);
}
template <class S, class T>
ostream& operator<<(ostream& os, const pair<S, T>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream& operator<<(ostream& os, const map<S, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
void prc(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}
struct node {
  long long c;
  struct node* next[2];
  long long cnt;
  node() {
    for (long long i = 0; i < 2; i++) next[i] = NULL;
    cnt = 0;
  }
};
node* root = new node();
void insertString(long long num) {
  long long i;
  node* cur = root;
  cur->cnt++;
  long long c;
  for (i = 30; i >= 0; i--) {
    c = ((num & (1 << i)) > 0) ? 1 : 0;
    if (cur->next[c] == NULL) {
      cur->next[c] = new node();
    }
    cur = cur->next[c];
    cur->cnt++;
  }
}
long long maxXOR(long long num) {
  long long i;
  node* cur = root;
  long long c;
  long long val = 0;
  for (i = 30; i >= 0; i--) {
    c = ((num & (1 << i)) > 0) ? 1 : 0;
    if (cur->next[1 - c] != NULL && (cur->next[1 - c]->cnt) > 0) {
      val += (1 << i);
      cur = cur->next[1 - c];
    } else {
      cur = cur->next[c];
    }
  }
  return val;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, i, j, k, n, m;
  long long x, y, l, r;
  cin >> n;
  vector<long long> v(n);
  long long xr = 0;
  for (i = 0; i < n; i++) {
    cin >> v[i];
    xr ^= v[i];
  }
  long long cur_xor = 0;
  long long ans = xr;
  insertString(0);
  for (i = 0; i < n; i++) {
    ans = max(ans, maxXOR(cur_xor ^ xr));
    cur_xor ^= v[i];
    insertString(cur_xor);
  }
  ans = max(ans, maxXOR(0));
  cout << ans << endl;
  return 0;
}
