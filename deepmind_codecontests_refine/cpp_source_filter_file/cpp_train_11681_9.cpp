#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, int> > tri, st, dr;
bool isbigger(int x, int y) {
  cout << "2 1 " << x << " " << y << "\n";
  cout.flush();
  int semn;
  cin >> semn;
  return semn == 1;
}
long long calcarea(int x, int y) {
  cout << "1 1 " << x << " " << y << "\n";
  cout.flush();
  long long ans;
  cin >> ans;
  return ans;
}
int main() {
  int n, first = 1, second = 2;
  cin >> n;
  for (int i = 3; i <= n; ++i)
    if (isbigger(i, second)) second = i;
  pair<long long, int> mxarea = {-1, -1};
  for (int i = 2; i <= n; ++i) {
    if (i == second) continue;
    tri.push_back({calcarea(2, i), i});
    if (mxarea.first < tri.back().first) mxarea = tri.back();
  }
  for (auto x : tri) {
    if (x == mxarea) continue;
    if (isbigger(x.second, mxarea.second))
      st.push_back(x);
    else
      dr.push_back(x);
  }
  sort(st.begin(), st.end());
  sort(dr.begin(), dr.end());
  reverse(dr.begin(), dr.end());
  cout << "0 " << first << " " << second << " ";
  for (auto x : st) cout << x.second << " ";
  cout << mxarea.second << " ";
  for (auto x : dr) cout << x.second << " ";
  return 0;
}
