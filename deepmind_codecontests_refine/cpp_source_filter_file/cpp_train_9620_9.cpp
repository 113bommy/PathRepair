#include <bits/stdc++.h>
using namespace std;
struct lex_compare {
 public:
  bool operator()(const pair<long long, long long>& lhs,
                  const pair<long long, long long>& rhs) const {
    if (lhs.second == rhs.second) return lhs.first < rhs.first;
    return (lhs.second > rhs.second);
  }
};
class trp {
 public:
  long long a, b, c;
  trp() {
    this->a = 0;
    this->b = 0;
    this->c = 0;
  }
  trp(long long a, long long b, long long c) {
    this->a = a;
    this->b = b;
    this->c = c;
  }
};
class node {
 public:
  long long id, a, l;
  vector<node*> v;
  vector<pair<node*, long long>> vm;
  node() { id = 0, a = 0, l = 0; }
  void adn(node* t) {
    v.push_back(t);
    this->l++;
  }
  void adn(node* t, long long x) { vm.push_back({t, x}), l++; }
};
node* nnd(long long a = 0, long long i = 1) {
  node* t = new node();
  t->a = a;
  t->id = i;
  return t;
}
long long pw(long long a, long long b, long long m) {
  if (b == 0) return 1;
  long long t = (pw(a, b / 2, m)) % m;
  t = (t * t) % m;
  if (b % 2 == 0) return t;
  return (a * t) % m;
}
long long gc(long long a, long long b) {
  if (b == 0) return a;
  return gc(b, a % b);
}
vector<string> splt(string x, char w) {
  vector<string> v;
  string s;
  int l = x.length();
  for (int i = 0; i < l; i++) {
    if (x[i] == w) {
      v.push_back(s);
      s = "";
    } else {
      s.push_back(x[i]);
    }
  }
  v.push_back(s);
  return v;
}
void ioe() {
  freopen("in_1.txt", "r", stdin);
  freopen("out_1.txt", "w", stdout);
  freopen("er_1.txt", "w", stderr);
}
void solve() {
  string s;
  cin >> s;
  long long n = s.length();
  long long x = 0, y = 0, c = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'M')
      c++;
    else {
      x += c;
      if (x != 0) y = max(2 * y - c + 1, 0ll);
      c = 0;
    }
  }
  cout << (x + y) << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1;
  long long f = t;
  while (f--) {
    solve();
  }
}
