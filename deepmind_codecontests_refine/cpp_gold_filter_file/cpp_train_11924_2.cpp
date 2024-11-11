#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int N, M, arr[maxn], cnt[maxn], res;
vector<int> v;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    if (arr[i] <= M) cnt[arr[i]]++;
  }
  for (int i = M; i >= 1; i--)
    for (int k = i + i; k <= M; k += i) cnt[k] += cnt[i];
  int mx = -1;
  for (int i = 1; i <= M; i++) {
    if (cnt[i] <= res) continue;
    res = cnt[i], mx = i;
  }
  if (mx == -1) {
    cout << "1 0" << endl;
    return 0;
  }
  for (int i = 1; i <= N; i++)
    if (mx > 0 && mx % arr[i] == 0) v.push_back(i);
  cout << mx << " " << res << '\n';
  for (int ck : v) cout << ck << " ";
}
