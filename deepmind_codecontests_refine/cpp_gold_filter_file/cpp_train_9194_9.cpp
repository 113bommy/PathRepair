#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int arr[110][2710];
int main() {
  arr[0][0] = 1;
  for (int i = 1; i <= 100; i++) {
    for (int j = 0; j <= 2700; j++) {
      for (int k = 0; k < 26; k++) {
        if (j >= k) {
          arr[i][j] += arr[i - 1][j - k];
          arr[i][j] %= MOD;
        }
      }
    }
  }
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; i++) {
    string s;
    cin >> s;
    int sum = 0;
    for (int j = 0; j < s.size(); j++) {
      sum += s[j] - 'a';
    }
    cout << arr[s.size()][sum] - 1 << '\n';
  }
}
