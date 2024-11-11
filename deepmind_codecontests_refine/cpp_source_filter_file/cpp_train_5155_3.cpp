#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, arr[200001], mini = 1e9, maxi = 0, sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] < mini) mini = arr[i];
  }
  for (int l = 0; l < 2; l++) {
    for (int i = 0; i < n; i++) {
      if (arr[i] == mini)
        sum = 0;
      else
        sum++;
      maxi = max(maxi, sum);
    }
  }
  cout << mini * n + maxi;
}
