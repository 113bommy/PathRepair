#include <bits/stdc++.h>
using namespace std;
const int Max = 2e5 + 10;
int bit[Max];
int n;
void upd(int i) {
  while (i <= n) {
    bit[i]++;
    i += i & -i;
  }
}
int get(int i) {
  int ans = 0;
  while (i >= 1) {
    ans += bit[i];
    i -= i & -i;
  }
  return ans;
}
int bs[Max];
void updbs(int i) {
  while (i <= n) {
    bs[i]--;
    i += i & -i;
  }
}
int getbs(int i) {
  int ans = 0;
  int sum = 0;
  for (int j = 20; j--;) {
    if ((1 << j) > n) continue;
    ans += (1 << j);
    if (sum + bs[ans] < i)
      sum += bs[ans];
    else
      ans -= (1 << j);
  }
  ans++;
  return ans;
}
int A[Max];
int B[Max];
int ANum[Max];
int BNum[Max];
int CNum[Max];
int C[Max];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= n; i++) cin >> B[i];
  for (int i = n; i >= 1; i--) {
    ANum[n - i] = get(A[i] + 1);
    upd(A[i] + 1);
  }
  for (int i = 1; i <= n; i++) bit[i] = 0;
  for (int i = n; i >= 1; i--) {
    BNum[n - i] = get(B[i] + 1);
    upd(B[i] + 1);
  }
  for (int i = 1; i < n; i++) {
    CNum[i] = ANum[i] + BNum[i] + CNum[i];
    while (CNum[i] >= i + 1) {
      CNum[i] -= i + 1;
      CNum[i + 1]++;
    }
  }
  for (int i = 1; i <= n; i++) bs[i] = i & -i;
  for (int i = n; i--;) {
    C[i] = getbs(CNum[i] + 1);
    updbs(C[i]);
    cout << (C[i] - 1) << " ";
  }
}
