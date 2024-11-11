#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  unsigned n, k;
  std::cin >> n >> k;
  const unsigned maxn = 500000;
  std::array<unsigned, maxn> a, b;
  for (unsigned i = 0; i < n; i++) std::cin >> a[i];
  for (unsigned i = 0; i < n; i++) std::cin >> b[i];
  unsigned l = 0, r = 0x3f3f3f3f;
  unsigned long long ans = 0;
  while (l <= r) {
    unsigned mid = (l + r) >> 1, cnt = 0;
    unsigned long long chk = 0;
    std::priority_queue<unsigned, std::vector<unsigned>,
                        std::greater<unsigned> >
        qa;
    std::priority_queue<unsigned> qb;
    for (unsigned i = 0; i < n; i++) {
      qa.push(a[i]);
      int choicea = (int)(qa.top() + b[i] - mid);
      int choiceb = qb.empty() ? INT_MAX : (int)(b[i] - qb.top());
      if (choicea <= choiceb && choicea <= 0) {
        chk += (unsigned long long)choicea;
        ++cnt;
        qa.pop();
        qb.push(b[i]);
      } else if (choiceb < choicea && choiceb < 0) {
        chk += (unsigned long long)choiceb;
        qb.pop();
        qb.push(b[i]);
      }
    }
    if (cnt < k)
      l = mid + 1;
    else {
      r = mid - 1;
      ans = chk + mid * 1ull * k;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
