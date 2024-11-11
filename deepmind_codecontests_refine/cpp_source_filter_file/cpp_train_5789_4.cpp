#include <bits/stdc++.h>
using namespace std;
long long int check(long long int a) {
  if (a >= 1000000000 + 7) a %= 1000000000 + 7;
  return a;
}
long long int check2(long long int a) {
  if (a > 0) return a;
  long long int b = a / 1000000000 + 7;
  a -= b * 1000000000 + 7;
  if (a < 0) a += 1000000000 + 7;
  return a;
}
long long int exp(long long int a, long long int n) {
  if (n == 0) return 1;
  if (n == 1) return check(a);
  long long int b = exp(a, n / 2);
  if (n % 2 == 0) return check(b * b);
  return check(b * check(b * a));
}
int arr[4][4];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) cin >> arr[i][j];
  for (int i = 0; i < 4; i++) {
    if (arr[i][3] == 1)
      for (int j = 0; j < 3; j++)
        if (arr[i][j] == 1) {
          cout << "YES";
          return 0;
        }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int k = (i + 1 + j) % 4;
      if (arr[i][3] == 1 && arr[i][3] == arr[k][j]) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
