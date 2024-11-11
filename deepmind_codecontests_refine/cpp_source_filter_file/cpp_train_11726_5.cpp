#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
int main() {
  int n;
  cin >> n;
  int sum = 0;
  int fl = 0;
  int pos1;
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    if (a[i] != 1 && a[i - 1] != 1 && i > 0) {
      pos1 = i;
      fl = 1;
    }
  }
  for (int i = 1; i <= sum; i++) b[i] = -1;
  if (fl == 0) {
    cout << "perfect";
  } else {
    cout << "ambiguous\n";
    int parent = 2;
    b[1] = 0;
    b[2] = 1;
    c[1] = 0;
    c[2] = 1;
    int child = a[1] + 2;
    for (int i = 1; i < n; i++) {
      b[child] = parent;
      c[child] = parent;
      parent += a[i];
      child += a[i];
    }
    int start = 1;
    for (int i = 3; i <= sum; i++) {
      if (b[i] != -1) {
        start = b[i];
      } else {
        b[i] = start;
        c[i] = b[i];
      }
    }
    int s1 = 0, s2;
    for (int j = 0; j < pos1; j++) s1 += a[j];
    s2 = s1;
    s2 += a[pos1];
    c[s2] = s1;
    for (int i = 1; i <= sum; i++) cout << b[i] << " ";
    cout << endl;
    for (int i = 1; i <= sum; i++) cout << c[i] << " ";
  }
  return 0;
}
