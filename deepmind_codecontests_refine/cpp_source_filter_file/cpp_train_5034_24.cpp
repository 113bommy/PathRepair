#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int N;
int ar[MAXN];
int sum;
int main() {
  cin >> N;
  for (int(i) = (1); (i) <= (N); (i)++) {
    scanf(" %d", ar + i);
    sum += ar[i];
  }
  if (sum % 3) return cout << 0 << endl, 0;
  int R = 0;
  int right = false;
  int res = 0;
  int before = 0;
  for (int(i) = (N); (i) >= (1); (i)--) {
    if (sum - R == sum / 3 && N - i >= 2) {
      res += right - before;
    }
    R += ar[i];
    if (R == sum / 3)
      right++, before = 1;
    else
      before = 0;
  }
  cout << res << endl;
  return 0;
}
