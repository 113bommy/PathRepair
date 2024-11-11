#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
int main() {
  int n, k;
  cin >> n >> k;
  int a[100001];
  for (int i = 0; i < 2 * n; i++) {
    a[i] = 2 * n - i;
  }
  for (int i = 0; i < k; i++) {
    swap(a[2 * i], a[2 * i + 1]);
  }
  for (int i = 0; i < 2 * n; i++) {
    cout << (i ? " " : "") << a[i];
  }
  cout << endl;
  return 0;
}
