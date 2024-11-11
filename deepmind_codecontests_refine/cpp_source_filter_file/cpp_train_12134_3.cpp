#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100000];
void nhap() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
}
void inrow() {
  int b = 1, maxlength = 1;
  for (int i = 0; i < n; i++) {
    if (a[i + 1] <= a[i]) {
      b = 1;
    } else {
      b++;
    }
    if (b >= maxlength) {
      maxlength = b;
    }
  }
  cout << maxlength;
}
int main() {
  nhap();
  inrow();
  return 0;
}
