#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, arr[3] = {0}, n, x;
  cin >> n;
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    arr[x - 1]++;
  }
  sort(arr, arr + 3);
  cout << arr[0] + arr[1];
}
