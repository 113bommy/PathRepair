#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s1, s2, s3;
  int n1 = 0, n2 = 0, n3 = 0;
  getline(cin, s1);
  getline(cin, s2);
  getline(cin, s3);
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' ||
        s1[i] == 'u')
      n1++;
  }
  for (int i = 0; i < s2.size(); i++) {
    if (s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' ||
        s2[i] == 'u')
      n2++;
  }
  for (int i = 0; i < s3.size(); i++) {
    if (s3[i] == 'a' || s3[i] == 'e' || s3[i] == 'i' || s3[i] == 'o' ||
        s3[i] == 'u')
      n3++;
  }
  if (n1 == 5 && n2 == 7 && n3 == 5)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
