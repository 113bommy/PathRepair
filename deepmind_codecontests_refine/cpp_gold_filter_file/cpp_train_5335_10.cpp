#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int arr[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    int a = 0, b = 0;
    int A = 0, B = 0;
    int ind1 = 0, ind2 = n - 1;
    int cnt = 0;
    while (ind1 <= ind2) {
      bool flag1 = false, flag2 = false;
      A = 0;
      while (A <= B && ind1 <= ind2) {
        A += arr[ind1];
        a += arr[ind1++];
        flag1 = true;
      }
      B = 0;
      while (B <= A && ind1 <= ind2) {
        B += arr[ind2];
        b += arr[ind2--];
        flag2 = true;
      }
      cnt += flag1;
      cnt += flag2;
    }
    cout << cnt << " " << a << " " << b << "\n";
  }
}
