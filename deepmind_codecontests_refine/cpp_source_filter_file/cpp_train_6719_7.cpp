#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, count = 0, FirstPart = 0, SecondPart = 0, mx, arr[102];
  cin >> n >> a;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  if (arr[a] == 1) count++;
  SecondPart = n - a;
  FirstPart = n - SecondPart - 1;
  if (FirstPart < SecondPart) {
    for (int i = a + 1, j = a - 1; j != 0; i++, j--) {
      if (arr[i] == 1 && arr[j] == 1) count += 2;
    }
    for (int i = a * 2; i <= n; i++) {
      if (arr[i] == 1) count += 2;
    }
  } else if (SecondPart < FirstPart) {
    for (int i = a + 1, j = a - 1; i != n + 1; i++, j--) {
      if (arr[i] == 1 && arr[j] == 1) count += 2;
    }
    for (int i = 1; i <= n - SecondPart * 2 - 1; i++) {
      if (arr[i] == 1) count += 2;
    }
  } else {
    for (int i = a + 1, j = a - 1; j != 0; i++, j--) {
      if (arr[i] == 1 && arr[j] == 1) count += 2;
    }
  }
  cout << count;
  return 0;
}
