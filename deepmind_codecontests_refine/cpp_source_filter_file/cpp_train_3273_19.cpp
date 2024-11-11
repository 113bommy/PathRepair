#include <bits/stdc++.h>
using namespace std;
int arr[100000][2];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i][1] >> arr[i][2];
  }
  int res[100000];
  int ans_home[100000];
  int ans_away[100000];
  for (int i = 0; i < n; i++) {
    res[arr[i][1]]++;
  }
  for (int i = 0; i < n; i++) {
    ans_home[i] = n - 1;
    ans_home[i] += res[arr[i][2]];
    ans_away[i] = 2 * (n - 1) - ans_home[i];
  }
  for (int s = 0; s < n; s++) {
    cout << ans_home[s] << " " << ans_away[s] << endl;
  }
  return 0;
}
