#include <bits/stdc++.h>
using namespace std;
int maxx = 0;
int main() {
  int i, j, k, l, n, h[101] = {0};
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    h[a[i]]++;
  }
  for (int i = 0; i < 101; i++) {
    if (h[i] > maxx) maxx = h[i];
  }
  cout << endl;
  cout << maxx;
}
