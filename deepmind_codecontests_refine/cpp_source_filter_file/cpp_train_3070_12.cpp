#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const int n = 6;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.second < b.second);
}
void solve() {
  string s1, s2;
  cin >> s1 >> s2;
  string s3 = "";
  int cnt = 0;
  for (int i = 0; i < ((int)((s1).size())); i++) {
    if (s1[i] == s2[i])
      s3 += s1[i];
    else {
      if (cnt % 2 == 0)
        s3 += s1[i];
      else
        s3 += s2[i];
      cnt++;
    }
  }
  if (cnt % 2 != 0)
    cout << "impossible \n";
  else
    cout << s3 << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
}
