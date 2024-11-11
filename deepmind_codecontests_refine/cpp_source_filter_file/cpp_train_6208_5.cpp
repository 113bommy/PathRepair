#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 6, sum = 0;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  string res = "NO";
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = j; k < n; k++) {
        int team_score = arr[i] + arr[j] + arr[k];
        if (team_score == sum - team_score) {
          res = "YES";
          break;
        }
      }
    }
  }
  cout << res;
  return 0;
}
