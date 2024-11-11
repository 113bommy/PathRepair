#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  if (n == 1) {
    cout << "Yes";
    return 0;
  }
  long long int a[26] = {0};
  for (long long int i = 0; i < n; i++) {
    a[s[i] - 'a']++;
    if (a[s[i] - 'a'] >= 2) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
}
