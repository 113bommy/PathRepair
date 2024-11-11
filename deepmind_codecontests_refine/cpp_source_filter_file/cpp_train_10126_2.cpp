#include <bits/stdc++.h>
using namespace std;
long long dp[200005][2];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    long long arr[26] = {0};
    for (int i = 0; i < n; i++) {
      cin >> s;
      for (int j = 0; j < s.size(); j++) arr[s[j] - 'a']++;
    }
    for (int i = 0; i < 25; i++) {
      if (arr[i] % n != 0) {
        cout << "NO"
             << "\n";
        goto h;
      }
    }
    cout << "YES"
         << "\n";
  h:;
  }
  return 0;
}
