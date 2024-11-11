#include<iostream>
#include<algorithm>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int const MAXN = 3e5;
int N, m[MAXN], d[MAXN+1];

int main() {
  std::cin >> N;
  std::fill_n(m, N, 0);
  for(int i = 0; i < N; ++i) { int A; std::cin >> A; ++m[A-1]; }
  std::fill_n(d, N+1, 0);
  for(int i = 0; i < N; ++i) ++d[m[i]];
 
  int sum_D = 0, sum_iD = N, k = 1;
  for(int ans = N; ans >= 1; --ans) {
    sum_D += d[ans];
    sum_iD -= d[ans]*ans;
    int f = sum_iD/ans + sum_D + 1;
    for(int i = k; i < f; ++i) std::cout << ans << std::endl;
    k = f;#
  }
  while(k <= N) { std::cout << 0 << std::endl; ++k; }
  return 0;
}
