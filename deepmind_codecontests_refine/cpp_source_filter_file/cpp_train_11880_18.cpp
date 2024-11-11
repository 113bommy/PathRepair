#include <bits/stdc++.h>
using namespace std;
int arr[2000001], n;
void ans(int p) {
  if (p != 1) {
    ans(arr[p]);
  }
  cout << p;
}
int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> arr[i];
  }
  ans(n);
  return 0;
}
