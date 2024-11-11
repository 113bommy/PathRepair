#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int arr[5002];
  int ctr = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr[x]++;
    if (arr[x] == 1 && x <= n) {
      ctr++;
    }
  }
  cout << n - ctr;
  return 0;
}
