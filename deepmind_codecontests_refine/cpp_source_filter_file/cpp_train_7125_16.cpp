#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
long long arr[100010], n;
int Left[100010], Right[100010];
int main() {
  int test;
  cin >> n;
  (memset(arr, 0, sizeof(arr)));
  (memset(Left, 0, sizeof(Left)));
  (memset(Right, 0, sizeof(Right)));
  for (int i = 1; i < n; i++) {
    cin >> arr[i];
  }
  Left[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (arr[i - 1] < arr[i])
      Left[i] = Left[i - 1] + 1;
    else
      Left[i] = 1;
  }
  Right[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    if (arr[i] < arr[i + 1])
      Right[i] = Right[i + 1] + 1;
    else
      Right[i] = 1;
  }
  int Max = 0;
  for (int i = 1; i <= n; i++) {
    Max = max(Max, Left[i] + 1);
    Max = max(Max, Right[i] + 1);
    if (arr[i - 1] + 1 < arr[i + 1]) {
      Max = max(Max, Left[i - 1] + Right[i + 1] + 1);
    }
  }
  cout << Max << endl;
  return 0;
}
