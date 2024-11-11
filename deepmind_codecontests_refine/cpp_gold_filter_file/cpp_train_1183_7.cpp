#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int count = 1;
  int num = -1;
  cin >> n >> k;
  int x[50];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x, x + n);
  for (int i = 0; i < n; i++) {
    count = 1;
    for (int j = i + 1; j < n; j++) {
      if (x[j] >= x[i]) count++;
    }
    if (count == k) {
      num = x[i];
      break;
    }
  }
  if (num == -1)
    cout << num;
  else
    cout << num << " " << num;
}
