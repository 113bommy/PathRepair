#include <bits/stdc++.h>
using namespace std;
const int M = 100000 + 10;
int a[M];
int b[M];
int c[M];
struct NODE {
  int val;
  int idx;
  bool operator<(const NODE& x) const { return val < x.val; }
} node[M];
int main() {
  time_t t_start, t_end;
  t_start = clock();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    node[i].val = a[i];
    node[i].idx = i;
  }
  sort(node, node + n);
  int k = n / 3 + (n % 3 != 0);
  for (int i = 0; i < k; i++) {
    int j = node[i].idx;
    b[j] = i;
    c[j] = node[i].val - i;
  }
  for (int i = k; i < 2 * k && i < n; i++) {
    int j = node[i].idx;
    c[j] = i;
    b[j] = node[i].val - i;
  }
  for (int i = 2 * k; i < n; i++) {
    int j = node[i].idx;
    c[j] = n - 1 - i;
    b[j] = node[i].val - c[j];
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << c[i] << " ";
  }
  cout << endl;
  t_end = clock();
  return 0;
}
