#include <bits/stdc++.h>
class raw_input {
 public:
  template <typename T>
  raw_input& operator>>(T& arg) {
    if constexpr (std::is_integral<T>::value) {
      if constexpr (sizeof(T) == sizeof(int)) {
        scanf("%d", &arg);
      } else {
        scanf("%lld", &arg);
      }
    }
    if constexpr (std::is_floating_point<T>::value) {
      if constexpr (sizeof(T) == sizeof(double)) {
        scanf("%lf", &arg);
      } else {
        scanf("%LF", &arg);
      }
    }
    return *this;
  }
  raw_input& operator>>(char* arg) {
    scanf("%s", arg);
    return *this;
  }
  raw_input& operator>>(char& c) {
    while ((c = getchar()) != EOF && (c == ' ' || c == '\n'))
      ;
    return *this;
  }
} gin{};
using namespace std;
long long ans = -1;
using ll = long long;
bool v[200005];
int a[200005];
vector<int> g[200005];
pair<ll, ll> dfs(int node) {
  v[node] = true;
  vector<ll> good;
  ll sum = a[node];
  for (int i : g[node]) {
    if (v[i]) continue;
    pair<ll, ll> elem = dfs(i);
    ll item = elem.first;
    good.push_back(item);
    sum += elem.second;
  }
  sort(good.begin(), good.end());
  int sz = good.size();
  if (sz >= 2) {
    ans = max(ans, good[sz - 1] + good[sz - 2]);
  }
  good.push_back(sum);
  return make_pair(*max_element(good.begin(), good.end()), sum);
}
int main() {
  int n;
  gin >> n;
  for (int i = 0; i < n; ++i) gin >> a[i];
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    gin >> x >> y;
    --x;
    --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(0);
  if (ans == -1) {
    cout << "Impossible\n";
  } else {
    cout << ans << endl;
  }
  return 0;
}
