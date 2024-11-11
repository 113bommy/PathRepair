#include <bits/stdc++.h>
using namespace std;
long long int check(vector<long long int> arr, long long int n) {
  vector<long long int> dp(n - 1);
  for (long long int i = 1; i < n; i++) {
    dp[i - 1] = arr[i] - arr[i - 1];
  }
  long long int len = 1;
  long long int curr = 1;
  for (long long int i = 1; i < n - 1; i++) {
    if (dp[i - 1] == dp[i]) {
      curr++;
    } else {
      curr = 1;
    }
    len = max(len, curr);
  }
  return len + 1;
}
long long int start(vector<long long int> arr, long long int i) {
  return arr[i + 1] + (arr[i + 1] - arr[i + 2]);
}
long long int end(vector<long long int> arr, long long int i) {
  return arr[i - 1] + (arr[i - 1] - arr[i - 2]);
}
long long int mid(vector<long long int> arr, long long int i) {
  return (arr[i + 1] + arr[i - 1]) / 2;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long int t = 1;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, long long int> hash;
    long long int count = 0;
    for (long long int i = 0; i < 2 * n - 1; i += 2) {
      hash[toupper(s[i])]++;
      if (hash[s[i + 1]]) {
        hash[s[i + 1]]--;
      } else {
        count++;
      }
    }
    cout << count << endl;
  }
}
