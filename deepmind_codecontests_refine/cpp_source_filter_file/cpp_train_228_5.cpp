#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    long long arr[n];
    for (int i = 0; i < n; i++) arr[i] = 0;
    long long temp = 0;
    for (int i = 0; i < m; i++) {
      cin >> temp;
      arr[temp]++;
    }
    long long alp[26];
    for (int i = 0; i < 26; i++) alp[i] = 0;
    for (long long i = 0; i < n; i++) {
      alp[s[i] - 'a']++;
    }
    long long j = 0;
    for (long long i = n - 1; i >= 0; i--) {
      if (arr[i + 1] > 0) {
        j += arr[i + 1];
      }
      alp[s[i] - 'a'] += j;
    }
    for (int i = 0; i < 26; i++) cout << alp[i] << " ";
    cout << "\n";
  }
}
