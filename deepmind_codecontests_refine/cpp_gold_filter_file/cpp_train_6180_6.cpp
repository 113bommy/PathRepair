#include <bits/stdc++.h>
using namespace std;
int main() {
  int s1, s2, s3, s4, ctr = 0;
  cin >> s1 >> s2 >> s3 >> s4;
  if (s1 == s2) ctr++;
  if (s1 == s3) ctr++;
  if (s1 == s4) ctr++;
  if (s2 == s3 && s2 != s1) ctr++;
  if (s2 == s4 && s2 != s1) ctr++;
  if (s3 == s4 && (s3 != s2 && s3 != s1)) ctr++;
  cout << ctr;
}
