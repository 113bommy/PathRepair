#include <bits/stdc++.h>
using namespace std;
int n = 0;
long long arr[100009];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 30; i >= 0; i--) {
    long long nw = (1 << i);
    long long test = 0;
    int sz = 0;
    for (int j = 1; j <= n; j++) {
      if ((nw & arr[j]) == nw) {
        sz++;
        if (sz == 1)
          test = arr[j];
        else
          test = (arr[j] & test);
      }
    }
    if (sz >= 1 && (test & nw) == nw) {
      cout << sz << endl;
      for (int j = 1; j <= n; j++) {
        if ((nw & arr[j]) == nw) {
          cout << arr[j] << " ";
        }
      }
      return 0;
    }
  }
  return 0;
}
