#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 0;
  cin >> n;
  int s[n];
  for (int p = 0; p < n; p++) cin >> s[p];
  for (int i = 0; i < n; i++)
    for (int j = 1 + i; j < n; j++) {
      if (s[i] > s[j]) {
        k = s[i];
        s[i] = s[j];
        s[j] = k;
      }
    }
  for (int l = 0; l < n; l++) cout << s[l] << " ";
}
