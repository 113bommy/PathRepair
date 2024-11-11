#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16100100")
using namespace std;
template <typename T>
using min_heap = priority_queue<T, std::vector<T>, std::less<T> >;
template <typename T>
using max_heap = priority_queue<T, std::vector<T>, std::greater<T> >;
void init() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
}
int n;
int p[3000];
int main() {
  init();
  cin >> n;
  for (int i = 0; i < (n); i++) cin >> p[i];
  int t = 0;
  for (int i = 0; i < (n); i++) {
    for (int j = 0; j < (i); j++) {
      if (p[i] < p[j]) t++;
    }
  }
  cout << 2 * t - t % 2;
}
