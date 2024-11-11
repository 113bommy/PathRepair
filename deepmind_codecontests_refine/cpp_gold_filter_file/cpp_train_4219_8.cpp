#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, *a, sum = 0, count = 0;
  cin >> n >> m;
  a = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] < a[j]) swap(a[i], a[j]);
    }
  }
  int i = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    count++;
    if (sum >= m) {
      cout << count;
      break;
    }
  }
  return 0;
}
