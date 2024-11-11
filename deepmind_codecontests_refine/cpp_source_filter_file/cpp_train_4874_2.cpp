#include<bits/stdc++.h>
using namespace std;
#define long long LL
int main () {
  int N;
  cin >> N;
  vector<LL>A(N);
  vector<LL>B(N);
  vector<LL>dis(N);
  for (int i = 0; i < N; i ++) cin >> A[i];
  for (int i = 0; i < N; i ++) cin >> B[i];
  for (int i = 0; i < N; i ++) dis[i] = A[i] - B[i];
  sort(dis.begin(), dis.end());
  LL k = 0;
  int i = 0;
  while(dis[i] < 0) {
    k += dis[i];
    i ++;
  }
  int ans = i;
  for (int j = N - 1; j >= i; j --) {
    if (k >= 0) {
      cout << ans << endl;
      return 0;
    }
    k += dis[j];
    ans ++;
  }
  if (k >= 0) cout << ans << endl;
  else cout << -1 << endl;
}
  