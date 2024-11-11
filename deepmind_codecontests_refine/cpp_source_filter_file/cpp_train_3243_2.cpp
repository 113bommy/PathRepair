#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, a, b;
  cin >> n >> a >> b;
  long long m;
  m = b;
  long long arr[n];
  long long i, j;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (i = 0; i < n; i++) {
    if (arr[i] == 0) {
      if (b) {
        b--;
      } else {
        a--;
      }
    } else {
      if (b == m) {
        if (b) {
          b--;
        } else {
          a--;
        }
      } else {
        if (a) {
          a--;
          b++;
        } else {
          b--;
        }
      }
    }
    if (a == 0 && b == 0) {
      break;
    }
  }
  cout << i + 1 << '\n';
  return 0;
}
