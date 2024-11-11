#include <bits/stdc++.h>
using namespace std;
long long n, x, m, a, b, c, cnt, ans;
int arr[3];
int main() {
  ios_base::sync_with_stdio();
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr[x % 3]++;
  }
  cout << (arr[0] / 2 + min(arr[1], arr[2])) << endl;
}
