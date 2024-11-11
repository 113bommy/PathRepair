#include <bits/stdc++.h>
using namespace std;
const int N = int(1e6) + 5;
long long diff[N];
long long sum[N];
long long xs[N];
void init() {
  sum[1] = 1;
  for (int i = 2; i < N; ++i) {
    diff[i] = 1LL * i * i - 1LL * (i - 1) * (i - 1);
    sum[i] = sum[i - 1] + diff[i];
  }
}
bool isSquare(long long x) {
  return (long long)(sqrt(x)) * (long long)(sqrt(x)) == x;
}
int bs(int bot, int top, long long key) {
  while (bot <= top) {
    int mid = (bot + top) >> 1;
    if (sum[mid] == key) return mid;
    if (sum[mid] < key)
      bot = mid + 1;
    else
      top = mid - 1;
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  init();
  int n;
  cin >> n;
  for (int i = 2; i <= n; i += 2) cin >> xs[i];
  int begin = 1;
  long long now = 0;
  vector<long long> ans;
  for (int i = 2; i <= n; i += 2) {
    int id = -1;
    while (begin < N) {
      long long temp = sum[begin] + xs[i];
      if (!isSquare(temp)) {
        begin += 1;
        continue;
      }
      id = bs(begin, N - 1, temp);
      if (id != -1) {
        if (sum[begin] - now == 0) {
          cout << "No" << endl;
          return 0;
        }
        ans.push_back(sum[begin] - now);
        ans.push_back(sum[id] - sum[begin]);
        begin = id + 1;
        now = sum[id];
        break;
      }
      begin += 1;
    }
    if (id == -1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  for (long long x : ans) cout << x << " ";
  return 0;
}
