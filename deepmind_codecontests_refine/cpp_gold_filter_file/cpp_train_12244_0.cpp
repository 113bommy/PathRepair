#include <bits/stdc++.h>
using namespace std;
int n, k, arr[26];
string s;
int main() {
  cin >> n >> k >> s;
  for (auto i : s) arr[i - 'a']++;
  for (int i = 0; i < 26; ++i)
    if (arr[i] > k) return cout << "NO\n", 0;
  cout << "YES\n";
  return 0;
}
