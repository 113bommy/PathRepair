#include <bits/stdc++.h>
using namespace std;
int main() {
  int i;
  int a[256] = {0};
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  for (i = 0; i < s1.size(); i++) a[s1[i]]++;
  for (i = 0; i < s2.size(); i++) a[s2[i]]--;
  a[32] = 0;
  for (i = 0; i < 256; i++)
    if (a[i] < 0) {
      cout << "no";
      return 0;
    }
  cout << "yes";
  return 0;
}
