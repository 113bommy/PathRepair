#include <bits/stdc++.h>
using namespace std;
int a[(int)1e5], b[(int)1e5];
int main() {
  int n;
  cin >> n;
  if (!n & 1) return puts("-1"), 0;
  for (int(i) = (int)0; (i) <= (int)n - 1; ++(i)) {
    a[i] = i;
    cout << i << " \n"[i == n - 1];
  }
  for (int(i) = (int)1; (i) <= (int)n - 1; ++(i)) {
    b[i - 1] = i;
    cout << i << " ";
  }
  cout << 0 << endl;
  for (int(i) = (int)1; (i) <= (int)n; ++(i)) {
    cout << (a[i - 1] + b[i - 1]) % n << " \n"[i == n];
  }
}
