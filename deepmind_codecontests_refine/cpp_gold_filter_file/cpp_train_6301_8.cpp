#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int ans;
int GetRightPosition(int A[], int l, int r, int key) {
  int m;
  while (r - l > 1) {
    m = l + (r - l) / 2;
    if (A[m] <= key)
      l = m;
    else
      r = m;
  }
  return l;
}
int GetLeftPosition(int A[], int l, int r, int key) {
  int m;
  while (r - l > 1) {
    m = l + (r - l) / 2;
    if (A[m] >= key)
      r = m;
    else
      l = m;
  }
  return r;
}
void updateans(int A[], int st, int ed) {
  int mid = (A[ed] - A[st]) / 2 + A[st];
  if ((A[ed] - A[st]) % 2 == 0) {
    int p1 = GetRightPosition(A, st, ed + 1, mid);
    int p2 = GetLeftPosition(A, st - 1, ed, mid);
    ans = min(ans, min(A[ed] - A[p1], A[p2] - A[st]));
  } else {
    int p1 = GetRightPosition(A, st, ed + 1, mid);
    int p2 = GetLeftPosition(A, st - 1, ed, mid + 1);
    ans = min(ans, min(A[ed] - A[p1], A[p2] - A[st]));
  }
}
char s[N];
int num[N];
int main() {
  int n, k;
  scanf("%d%d%s", &n, &k, s);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') num[cnt++] = i;
  }
  int st = 0, ed = k;
  ans = num[ed];
  updateans(num, st, ed);
  for (; ed < cnt; ed++, st++) updateans(num, st, ed);
  cout << ans << endl;
  return 0;
}
