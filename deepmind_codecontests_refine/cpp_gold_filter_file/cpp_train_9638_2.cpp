#include <bits/stdc++.h>
using namespace std;
int n, arr[2005], counts[2005];
char c = 'a';
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    counts[i] = arr[i];
    if (arr[i] != 0) {
      for (int j = i - 1; j >= 0; j--) {
        arr[j] -= (i - j + 1) * arr[i];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < counts[i - 1]; j++) {
      for (int k = 0; k < i; k++) {
        cout << c;
      }
      c = ((c == 'a') ? 'b' : 'a');
    }
  }
}
