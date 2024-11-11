#include <bits/stdc++.h>
using namespace std;
long long int dif(long long int a, long long int b) {
  return ((a / b) + (a % b != 0));
}
long long int a1[200200], a2[200200], a3[200200];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  string s1, s2, s3;
  for (long long int i = 0; i < 200000; i++) {
    if (i % 3 == 0) {
      s1 += 'R';
      s2 += 'G';
      s3 += 'B';
    }
    if (i % 3 == 1) {
      s1 += 'B';
      s2 += 'B';
      s3 += 'R';
    }
    if (i % 3 == 2) {
      s1 += 'G';
      s2 += 'R';
      s3 += 'G';
    }
  }
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    string t;
    cin >> t;
    for (long long int i = 0; i < n + 1; i++) {
      a1[i] = a2[i] = a3[i] = 0;
    }
    for (long long int i = 1; i <= n; i++) {
      a1[i] = a1[i - 1] + (t[i - 1] != s1[i - 1]);
      a2[i] = a2[i - 1] + (t[i - 1] != s2[i - 1]);
      a3[i] = a3[i - 1] + (t[i - 1] != s3[i - 1]);
    }
    long long int ans1 = 1e15, ans2 = 1e15, ans3 = 1e15, h1, h2, h3;
    for (long long int i = k; i <= n; i++) {
      h1 = a1[i] - a1[i - k];
      h2 = a2[i] - a2[i - k];
      h3 = a3[i] - a3[i - k];
      ans1 = min(ans1, h1);
      ans2 = min(ans2, h2);
      ans3 = min(ans3, h3);
    }
    cout << min(ans1, min(ans2, ans3)) << endl;
  }
  return 0;
}
