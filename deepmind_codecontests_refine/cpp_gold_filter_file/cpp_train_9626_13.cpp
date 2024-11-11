#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200005];
int b[200005];
int binary_st(int pd) {
  int st = 0, en = m - 1, mid, res = -1;
  while (1) {
    mid = (st + en) / 2;
    if (b[mid] > pd) {
      en = mid - 1;
    } else if (b[mid] <= pd) {
      res = mid;
      st = mid + 1;
    }
    if (st > en) {
      break;
    }
  }
  res++;
  return (res * 2) + (m - res) * 3;
}
int main() {
  int i, j, k;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  for (i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  long long mx = -99999999999, a_ans = -1, b_ans = -1;
  for (i = 0; i < n; i++) {
    int tmp = binary_st(a[i] - 1);
    int temp = (i)*2 + (n - i) * 3;
    if (temp - tmp > mx) {
      a_ans = temp;
      b_ans = tmp;
      mx = temp - tmp;
    }
  }
  if (n * 2 - m * 2 > mx) {
    a_ans = n * 2;
    b_ans = m * 2;
  }
  cout << a_ans << ':' << b_ans << endl;
  return 0;
}
