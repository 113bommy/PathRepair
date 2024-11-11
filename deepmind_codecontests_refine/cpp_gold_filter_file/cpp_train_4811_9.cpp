#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string s1 = s;
  for (long long int i = k; i < n; i++) s1[i] = s1[i - k];
  if (s > s1) {
    long long int j = k - 1;
    while (s1[j] == '9') {
      s1[j--] = '0';
    }
    s1[j] += 1;
    for (long long int i = k; i < n; i++) s1[i] = s1[i - k];
  }
  cout << n;
  cout << "\n";
  cout << s1;
  cout << "\n";
}
