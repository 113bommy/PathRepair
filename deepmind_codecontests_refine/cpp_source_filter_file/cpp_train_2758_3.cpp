#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  h[0] = 1;
  h[n - 1] = 1;
  for (int i = 1; i < n; i++) {
    if (h[i] > h[i - 1] + 1) {
      h[i] = h[i - 1] + 1;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (h[i] > h[i + 1] + 1) {
      h[i] = h[i + 1] + 1;
    }
  }
  int maxHeight = 1;
  for (int i = 0; i < n; i++) {
    if (h[i] > maxHeight) {
      maxHeight = h[i];
    }
  }
  cout << maxHeight << '\n';
}
