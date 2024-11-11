#include <bits/stdc++.h>
using namespace std;
int n, a[26];
string s;
int main() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) a[s[i] - 'a']++;
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < a[i]; j++) cout << (char)(i + 'a');
}
