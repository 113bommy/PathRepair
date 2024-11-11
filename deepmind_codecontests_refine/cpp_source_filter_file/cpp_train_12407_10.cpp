#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> n;
  vector<int> c(n);
  vector<int> a(n);
  vector<int> b(n);
  char h;
  for (int i = 0; i < n; i++) {
    cin >> h;
    c[i] = h - '0';
  }
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  int maxo = 0;
  for (int i = 0; i < 1000; i++) {
    int k = 0;
    for (int j = 0; j < n; j++) {
      if (i > b[j])
        k += ((i - b[j]) / a[j] + 1 + c[j]) % 2;
      else
        k += c[j];
    }
    maxo = max(maxo, k);
  }
  cout << maxo;
}
