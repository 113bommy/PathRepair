#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != '0' && i != n - 1) {
        sum += s[i] - 48;
        cnt++;
      }
    }
    cout << sum + cnt + s[n - 1] << endl;
  }
}
