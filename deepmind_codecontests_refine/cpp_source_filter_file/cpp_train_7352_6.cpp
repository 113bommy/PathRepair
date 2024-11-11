#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int len[n];
  for (int i = 0; i < n; i++) {
    cin >> len[i];
  }
  int dead = 0, j = n - 1;
  for (int i = n - 1; i > 0 && j > 0; i--) {
    if (j > i) {
      j = i;
    }
    if (i - len[i] < j) {
      if (i - len[i] <= 0) {
        dead += i;
        j = 0;
      } else {
        dead += j - i + len[i];
        j = i - len[i];
      }
    }
  }
  cout << n - dead;
  return 0;
}
