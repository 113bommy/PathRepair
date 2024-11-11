#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200009;
long long N, M;
long long Max[MAXN], A[MAXN];
long long maxLL(long long num1, long long num2) {
  return (num1 > num2 ? num1 : num2);
}
void Update(int x, int nh) {
  for (int i = x; i <= N; i += (i & (-i))) Max[i] = maxLL(Max[i], nh);
}
long long Find(int x) {
  long long ret = 0;
  for (int i = x; i >= 1; i -= (i & (-i))) ret = maxLL(ret, Max[i]);
  return ret;
}
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) Max[i] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    Update(i, A[i]);
  }
  cin >> M;
  for (int i = 1; i <= M; i++) {
    long long Xx, Yy;
    cin >> Xx >> Yy;
    long long Ans = Find(Xx);
    Update(1, Ans + Yy);
    cout << Ans << "\n";
  }
}
