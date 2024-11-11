#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m, x = 0, i;
  cin >> n >> m;
  pair<int, int> A[n];
  vector<int> st(n), en(n);
  for (i = 0; i < n; i++) scanf("%d %d", &A[i].first, &A[i].second);
  sort(A, A + n);
  for (i = 0; i < n; i++) {
    st[i] = A[i].first;
    en[i] = A[i].second;
  }
  if (st[0] != 0) x = 1;
  for (i = 1; i < n && x != 1; i++) {
    if (st[i] > en[i - 1]) {
      x = 1;
      break;
    }
    if (en[i - 1] > en[i]) en[i] = en[i - 1];
  }
  if (en[n - 1] != m) x = 1;
  if (x == 1)
    cout << "NO";
  else
    cout << "YES";
}
