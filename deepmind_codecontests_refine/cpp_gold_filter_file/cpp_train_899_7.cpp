#include <bits/stdc++.h>
using namespace std;
void init();
void solve();
int main() {
  try {
    init();
    solve();
  } catch (...) {
    return 0;
  }
  return 0;
}
template <class T>
inline bool checkMin(T& a, T b) {
  return (a > b ? a = b, 1 : 0);
}
template <class T>
inline bool checkMax(T& a, T b) {
  return (a < b ? a = b, 1 : 0);
}
class Scanner {
 private:
  istream& ist;

 public:
  Scanner(istream& in) : ist(in) {}
  string next() {
    string r;
    ist >> r;
    return r;
  }
  string nextLine() {
    string r;
    getline(ist, r);
    return r;
  }
  int nextInt() {
    int r;
    ist >> r;
    return r;
  }
  double nextDouble() {
    double r;
    ist >> r;
    return r;
  }
  char nextChar() {
    char r;
    ist >> r;
    return r;
  }
};
Scanner sc(cin);
void ALERT(bool judgememt, const char* phrase) {
  if (judgememt) {
    puts(phrase);
    throw "ALERT";
  }
}
bool alert(bool judgememt, const char* phrase) {
  if (judgememt) puts(phrase);
  return judgememt;
}
const int N = 10005;
pair<int, int> v[N];
int n;
set<pair<int, int> > ans;
void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &v[i].first, &v[i].second);
  sort(v, v + n);
}
void go(int l, int r) {
  if (l > r) return;
  if (l == r) {
    ans.insert(v[l]);
    return;
  }
  int m = (l + r) / 2;
  for (int i = l; i <= r; i++)
    ans.insert(pair<int, int>(v[m].first, v[i].second));
  go(l, m - 1);
  go(m + 1, r);
}
void solve() {
  go(0, n - 1);
  for (int i = 0; i < n; i++) ans.insert(v[i]);
  printf("%d\n", ans.size());
  for (auto v : ans) {
    printf("%d %d\n", v.first, v.second);
  }
}
