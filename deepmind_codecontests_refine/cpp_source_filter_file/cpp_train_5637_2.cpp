#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int A[MAXN];
bool present[100005];
int N;
int check(int sum) {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    int x = sum - A[i];
    if (x < 0 || x >= 100005 || x == A[i]) continue;
    if (present[x]) cnt++;
  }
  return cnt / 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);
  for (int i = 0; i < N; i++) present[A[i]] = 1;
  int ans = 0;
  for (int i = 0; i <= 1e5; i++) {
    ans = max(ans, check(i));
  }
  cout << max(ans, 1);
}
