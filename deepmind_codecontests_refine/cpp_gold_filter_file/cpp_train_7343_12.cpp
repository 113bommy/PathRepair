#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ar[n];
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  for (int i = n - 1; i > 0; --i)
    for (int j = 0; j < i; ++j)
      if (ar[j + 1] < ar[j]) {
        cout << j + 1 << ' ' << j + 2 << endl;
        swap(ar[j], ar[j + 1]);
      }
  return 0;
}
