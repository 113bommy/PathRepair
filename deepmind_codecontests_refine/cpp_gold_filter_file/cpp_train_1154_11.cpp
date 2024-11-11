#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a[200000], i, count = 0, temp = 0;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    temp = temp + a[i];
    count = 0;
    if (temp >= m) {
      count = temp / m;
      temp = temp % m;
    }
    cout << count << " ";
  }
}
