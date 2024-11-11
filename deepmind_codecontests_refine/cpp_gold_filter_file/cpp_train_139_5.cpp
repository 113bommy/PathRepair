#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a_g[n];
  int arr[101] = {0};
  int a_h[n];
  for (int i = 0; i < n; i++) {
    cin >> a_h[i];
    cin >> a_g[i];
    arr[a_g[i]]++;
  }
  int ctr = 0;
  for (int i = 0; i < n; i++) {
    ctr += arr[a_h[i]];
  }
  cout << ctr;
  return 0;
}
