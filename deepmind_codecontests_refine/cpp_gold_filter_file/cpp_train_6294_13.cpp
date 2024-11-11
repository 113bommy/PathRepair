#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s1, s2, s3, ans;
  cin >> s1 >> s2 >> s3;
  int a[3] = {0};
  if (s1[1] == '>') {
    a[(s1[0] - 'A')]++;
  } else
    a[(s1[2] - 'A')]++;
  if (s2[1] == '>') {
    a[(s2[0] - 'A')]++;
  } else
    a[(s2[2] - 'A')]++;
  if (s3[1] == '>') {
    a[(s3[0] - 'A')]++;
  } else
    a[(s3[2] - 'A')]++;
  if (a[0] == a[1] || a[0] == a[2] || a[1] == a[2]) {
    cout << "Impossible";
  } else {
    if (a[0] > a[1] && a[0] > a[2]) {
      ans[2] = 'A';
      if (a[1] > a[2]) {
        ans[0] = 'C';
        ans[1] = 'B';
      } else {
        ans[0] = 'B';
        ans[1] = 'C';
      }
    }
    if (a[1] > a[0] && a[1] > a[2]) {
      ans[2] = 'B';
      if (a[0] > a[2]) {
        ans[0] = 'C';
        ans[1] = 'A';
      } else {
        ans[0] = 'A';
        ans[1] = 'C';
      }
    }
    if (a[2] > a[1] && a[2] > a[0]) {
      ans[2] = 'C';
      if (a[1] > a[0]) {
        ans[0] = 'A';
        ans[1] = 'B';
      } else {
        ans[0] = 'B';
        ans[1] = 'A';
      }
    }
    for (int i = 0; i < 3; i++) cout << ans[i];
  }
  return 0;
}
