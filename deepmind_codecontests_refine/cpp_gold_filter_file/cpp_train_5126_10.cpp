#include <bits/stdc++.h>
using namespace std;
bool search(const int* arr, int len, int el) {
  for (int i = 0; i < len; ++i) {
    if (arr[i] == el) {
      return true;
    }
  }
  return false;
}
void doFunction() {
  int n, x;
  cin >> n >> x;
  int* a = (int*)malloc((n) * sizeof(int));
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int len = n + x;
  int k = 0;
  for (int i = 1; i < len + 1; ++i) {
    if (search(a, n, i)) {
      ++k;
    } else {
      if (x != 0) {
        --x;
        ++k;
      } else {
        cout << k << endl;
        free(a);
        return;
      }
    }
  }
  cout << x + k << endl;
  free(a);
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    doFunction();
  }
  return 0;
}
