#include <bits/stdc++.h>
using namespace std;
const int OO = (int)1e9 + 1;
const int MAX = 1e5 + 1;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x, arr[3] = {};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr[x]++;
  }
  if (!arr[1])
    cout << 0 << endl;
  else if (arr[1] > arr[2])
    cout << arr[2] + (arr[1] - arr[2]) / 3 << endl;
  else if (arr[2] >= arr[1])
    cout << arr[2];
}
