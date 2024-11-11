#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool elem(set<T> st, T val) {
  return (st.find(val) != st.end());
}
template <typename T>
void printv(vector<T> vt) {
  if (vt.size() == 0) return;
  for (int i = 0; i < (int)vt.size() - 1; ++i) cout << vt[i] << " ";
  cout << vt[vt.size() - 1] << endl;
}
string rs;
vector<int> n(3);
vector<int> g(3);
vector<int> p(3);
unsigned long long r;
bool fb(unsigned long long t) {
  unsigned long long r1 = r;
  for (int i = 0; i < (int)3; ++i) {
    if (t * n[i] < g[i]) continue;
    unsigned long long bp = (t * n[i] - g[i]) * p[i];
    if (r1 < bp) return false;
    r1 -= bp;
  }
  return true;
}
int main(void) {
  cin >> rs;
  for (int i = 0; i < (int)3; ++i) cin >> g[i];
  for (int i = 0; i < (int)3; ++i) cin >> p[i];
  for (int i = 0; i < (int)3; ++i) n[i] = 0;
  cin >> r;
  for (int i = 0; i < (int)rs.length(); ++i) {
    if (rs[i] == 'B') n[0]++;
    if (rs[i] == 'S') n[1]++;
    if (rs[i] == 'C') n[2]++;
  }
  unsigned long long l = 0;
  unsigned long long r = 100000000000000000;
  while (r - l > 1) {
    unsigned long long t = (l + r) / 2;
    if (fb(t))
      l = t;
    else
      r = t;
  }
  cout << l << endl;
  return 0;
}
