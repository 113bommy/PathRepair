#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int loc = -1, count = 0;
  for (int i = 1; i < n - 1; i++) {
    if (a[i] == 0 && a[i + 1] == 1 && a[i - 1] == 1 && loc != i - 1) {
      count++;
      loc = i + 1;
    }
  }
  cout << count;
  return 0;
}
