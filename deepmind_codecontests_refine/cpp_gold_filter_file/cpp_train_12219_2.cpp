#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, n;
  int s1 = 0, s2 = 0, s3 = 0;
  ;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (i % 3 == 0)
      s3 += x;
    else if (i % 3 == 1)
      s1 += x;
    else
      s2 += x;
  }
  if (s1 > s2 and s1 > s3)
    cout << "chest";
  else if (s2 > s1 and s2 > s3)
    cout << "biceps";
  else
    cout << "back";
  return 0;
}
