#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int* a = new int[n];
  int* b = new int[n];
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    a[i] = tmp;
    b[i] = tmp;
  }
  sort(b, b + n);
  int start = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      start = i;
      break;
    }
  }
  if (start == -1) {
    cout << "yes" << endl;
    cout << "1 1" << endl;
  } else {
    int end = -1;
    for (int i = 0; i < n; i++) {
      if (b[i] == a[start]) {
        end = i;
        break;
      }
    }
    if (start > end) {
      int tmp = start;
      start = end;
      end = tmp;
    }
    for (int i = 0; i < (end - start + 1) / 2; i++) {
      int tmp = a[start + i];
      a[start + i] = a[end - i];
      a[end - i] = tmp;
    }
    bool ans = true;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        ans = false;
        break;
      }
    }
    if (ans) {
      cout << "yes" << endl;
      cout << start + 1 << " " << end + 1 << endl;
    } else {
      cout << "no" << endl;
    }
  }
  delete[] a;
  delete[] b;
  return 0;
}
