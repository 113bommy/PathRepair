#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, A, B;
  cin >> N >> A >> B;
  vector<long long> h(N);
  for (int i = 0; i < N; ++i) cin >> h[i];
  long long l = 0, r = 1LL << 22;
  while (l + 1 != r) {
    long long c = (l + r) / 2, need = 0;
    for (int i = 0; i < N; ++i)
      need += max(0LL, h[i] - B * c + A - B - 1) / (A - B);
    if (need <= c)
      r = c;
    else
      l = c;
  }
  cout << r << endl;
  return 0;
}
