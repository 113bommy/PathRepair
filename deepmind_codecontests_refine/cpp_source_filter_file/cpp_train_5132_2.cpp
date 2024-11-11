#include <bits/stdc++.h>
using namespace std;
int main() {
  string A, B;
  cin >> A >> B;
  int ac4 = 0, ac7 = 0, bc4 = 0, bc7 = 0;
  for (int i = 0; i < A.size(); ++i)
    if (A[i] == '4')
      ac4++;
    else
      ac7++;
  for (int i = 0; i < B.size(); ++i)
    if (B[i] == '4')
      bc4++;
    else
      bc7++;
  int cnt = (bc4 - ac4);
  int ans = 0;
  for (int i = 0; i < A.size(); ++i)
    if (bc4 > 0 && A[i] == '7' && B[i] == '4')
      B[i] = '7', cnt--, ans++;
    else if (bc4 < 0 && A[i] == '4' && B[i] == '7')
      B[i] = '7', cnt--, ans++;
  ans *= 2;
  for (int i = 0; i < A.size(); ++i) ans += A[i] != B[i];
  ans /= 2;
  cout << ans << endl;
}
