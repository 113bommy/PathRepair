#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  float ans = 0;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    ans = ans + arr[i];
  }
  cout << ans / n;
}
