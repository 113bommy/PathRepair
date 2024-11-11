#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  int arr[30] = {};
  for (int i = 0; i < k; i++) {
    char ch;
    cin >> ch;
    arr[ch - 97] = 1;
  }
  long long ans = 0, cons = 0;
  for (int i = 0; i < n; i++) {
    if (arr[str[i] - 97] == 1) {
      cons++;
    } else {
      ans += (cons * (cons + 1)) / 2;
      cons = 0;
    }
  }
  ans += (cons * (cons + 1)) / 2;
  cout << ans << endl;
  return 0;
}
