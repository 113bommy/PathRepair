#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int N = int(2e5) + 10;
long long int L[N], T[N], r;
int main() {
  int n;
  scanf("%d", &n);
  scanf("%lld", &r);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &L[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &T[i]);
  }
  vector<long long int> ans;
  long long int nxt = 0;
  long long int s = 0;
  long long int szans = 0;
  for (int i = 1; i <= n; i++) {
    if (T[i] < L[i]) {
      puts("-1");
      return 0;
    }
    long long int dleft = L[i] - max(0ll, nxt - s);
    dleft = max(dleft, 0ll);
    long long int tleft = T[i] - L[i] + dleft;
    s = s + T[i] - tleft;
    if (tleft >= 2 * dleft) {
      s += 2 * dleft;
      continue;
    }
    long long int x = tleft - dleft;
    assert(x >= 0);
    ans.push_back(s + 2 * x);
    szans++;
    nxt = s + 2 * x + r;
    s = s + 2 * x;
    long long int temp = (s + dleft - x - nxt) / r;
    if ((s + dleft - x - nxt) % r != 0 && s + dleft - x - nxt >= 0) temp++;
    long long int tnxt = nxt;
    nxt = nxt + r * temp;
    szans += temp;
    while (szans < int(1e5) && tnxt < s + dleft - x) {
      ans.push_back(tnxt);
      tnxt += r;
    }
    s = s + dleft - x;
  }
  printf("%lld\n", szans);
  if (szans > int(1e5)) return 0;
  for (auto x : ans) printf("%lld ", x);
  puts("");
  return 0;
}
