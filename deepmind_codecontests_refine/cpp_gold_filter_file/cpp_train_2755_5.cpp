#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[1000];
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  int k = 0;
  int t = 20000;
  for (int i = 2; i <= n; i++) {
    k = max(k, arr[i] - arr[i - 1]);
  }
  for (int i = 2; i < n; i++) {
    t = min(t, max(k, arr[i + 1] - arr[i - 1]));
  }
  cout << t << endl;
}
