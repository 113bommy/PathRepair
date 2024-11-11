#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-8;
int dr[]{-1, 1, 0, 0, 1, 1, -1, -1};
int dc[]{0, 0, 1, -1, 1, -1, 1, -1};
void run() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const int N = 2e5 + 1;
int cnt[N];
int main() {
  run();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  vector<int> ans(N);
  for (int i = 1; i < N; i++) {
    ans[i] = cnt[i];
    if (cnt[i - 1] > 1) {
      ans[i] += ans[i - 1];
    } else
      ans[i] += cnt[i - 1];
  }
  int mx = max_element(ans.begin(), ans.end()) - ans.begin(), mn;
  mn = mx;
  while (mn > 0 && ans[mx]) {
    ans[mx] -= cnt[mn];
    mn--;
  }
  deque<int> out;
  for (int i = mn + 1; i <= mx; i++) {
    if (cnt[i] & 1) {
      out.push_back(i);
    }
    while (cnt[i] > 1) {
      out.push_back(i);
      out.push_front(i);
      cnt[i] -= 2;
    }
  }
  cout << (int)(out.size()) << '\n';
  for (auto it : out) cout << it << ' ';
}
