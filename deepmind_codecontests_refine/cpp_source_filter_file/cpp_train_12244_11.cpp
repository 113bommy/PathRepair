#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int cnt[30];
int main() {
  cin >> n >> k;
  cin >> s;
  for (int i = 0; i < 26; i++) cnt[i] = 0;
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
  }
  int max = 0, sum = 0;
  for (int i = 0; i < 26; i++)
    if (cnt[i] > max) max = cnt[i];
  if (n < k || max > k)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
