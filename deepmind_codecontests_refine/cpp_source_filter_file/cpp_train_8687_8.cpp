#include <bits/stdc++.h>
using namespace std;
int solve(int A, int B, int n) {
  int count = 0;
  for (int i = 0; i < 32; i++) {
    if (((A >> i) & 1) != ((B >> i) & 1)) {
      count++;
    }
  }
  return count;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int arr[m + 1];
  for (int i = 0; i < m + 1; i++) {
    cin >> arr[i];
  }
  int c = 0;
  for (int i = m - 1; i >= 0; i--) {
    int temp = solve(arr[m], arr[i - 1], n);
    if (temp <= k) {
      c++;
    }
  }
  cout << c << endl;
  return 0;
}
