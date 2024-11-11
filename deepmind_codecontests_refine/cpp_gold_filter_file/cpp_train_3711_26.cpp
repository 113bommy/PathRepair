#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const long long mod = 1e9 + 7;
const int INF = 1e9;
const double eps = 1e-6;
int n;
long long num[maxn];
vector<long long> vec;
queue<long long> q[70];
int main() {
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &num[i]);
    ans ^= num[i];
    int now = -1;
    for (int j = 60; j >= 0; j--) {
      if ((num[i] & (1LL << j))) {
        now = j;
        break;
      }
    }
    q[now].push(i);
  }
  for (int i = 1; i <= n; i++) {
    int now = 0;
    for (int j = 0; j <= 60; j++) {
      if ((ans & (1LL << j)) && q[j].size()) {
        now = q[j].front();
        q[j].pop();
        break;
      }
    }
    if (now == 0) return puts("No"), 0;
    vec.push_back(num[now]);
    ans ^= num[now];
  }
  puts("Yes");
  reverse(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); i++) printf("%lld ", vec[i]);
  puts("");
}
