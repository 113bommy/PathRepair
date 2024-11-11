#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int arr[n];
  int minum = 32;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    minum = min(minum, arr[i]);
  }
  cout << (2 + (arr[2] ^ minum)) << endl;
  return 0;
}
