#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int a, b, c, d, ans = 0;
  cin >> a;
  vector<string> A(a);
  vector<long long int> B(300005, 0), C(300005, 0);
  for (b = 0; b < a; b++) cin >> A[b];
  for (b = 0; b < a; b++) {
    long long int count = 0, minn = 1000000;
    for (c = 0; c < A[b].length(); c++) {
      if (A[b][c] == '(')
        count++;
      else
        count--;
      minn = min(count, minn);
    }
    if (minn >= 0) {
      if (count < 0)
        C[0 - count]++;
      else
        B[count]++;
    } else {
      if (count < 0 && minn == count) {
        C[0 - count]++;
      }
    }
  }
  ans = ans + pow(2, B[0]);
  for (b = 1; b <= 300003; b++) {
    ans = ans + B[b] * C[b];
  }
  cout << ans << endl;
}
