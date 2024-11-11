#include <bits/stdc++.h>
using namespace std;
double eps = 1e-8;
int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  int b[n];
  int c[n];
  for (int p = 0; p < n; p++) {
    scanf("%d", &a[p]);
    b[p] = a[p];
    c[p] = p;
  }
  pair<int, int> pairs[n];
  for (int i = 0; i < n; ++i) pairs[i] = make_pair(b[i], c[i]);
  sort(pairs, pairs + n);
  for (int i = 0; i < n; ++i) {
    b[i] = pairs[i].first;
    c[i] = pairs[i].second;
  }
  int t = 1;
  for (int i = 0; i < n; i++) {
    int t1 = b[i];
    if (t1 >= t) {
      a[c[i]] = t1;
      t = t1;
    } else {
      a[c[i]] = t;
    }
    t++;
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
