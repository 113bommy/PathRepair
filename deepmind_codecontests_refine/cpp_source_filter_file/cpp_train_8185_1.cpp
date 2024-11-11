#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAX = 200002;
int arr[MAX];
int cnt[MAX];
int main() {
  int n, wrong = 0;
  cin >> n;
  for (int i = (1); i <= (n); i++) {
    cin >> arr[i];
  }
  string s;
  cin >> s;
  cnt[1] = s[0] - '0';
  for (int i = (2); i <= (n); i++) {
    cnt[i] = s[i - 1] - '0';
    cnt[i] += cnt[i - 1];
  }
  bool yes = 1;
  for (int i = (1); i <= (n); i++) {
    if (arr[i] != i) {
      int has = 0;
      if (arr[i] > i)
        has = cnt[arr[i] - 1] - cnt[i];
      else
        has = cnt[i - 1] - cnt[arr[i]];
      if (has < abs(arr[i] - i)) {
        yes = 0;
        break;
      }
    }
  }
  if (yes)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
