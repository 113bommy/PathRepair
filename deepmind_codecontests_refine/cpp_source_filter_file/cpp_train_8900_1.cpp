#include <bits/stdc++.h>
using namespace std;
long long n;
struct mang {
  long long first, second;
  bool operator<(const mang& o) const {
    if (first == o.first) return second < o.second;
    return first < o.first;
  }
};
mang a[1000005];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + 1 + n);
  long long tam1 = 1;
  long long tam2 = 0;
  long long res = 0;
  long long mx[100005];
  long long cs = 1;
  long long dem = 0;
  for (long long i = 1; i <= n; i++) {
    dem++;
    mx[cs] = max(mx[cs], a[i].second);
    if (dem == mx[cs] - mx[cs - 1]) {
      res++;
      dem = 0;
      cs++;
    }
  }
  if (dem == mx[cs] - mx[cs - 1]) {
    res++;
    dem = 0;
    cs++;
  }
  cout << res;
  return 0;
}
