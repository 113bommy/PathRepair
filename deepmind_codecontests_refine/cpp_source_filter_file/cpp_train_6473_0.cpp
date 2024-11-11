#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  int ans[2] = {0};
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    ans[arr[i] % 2]++;
  }
  cout << max(ans[0], ans[1]);
}
