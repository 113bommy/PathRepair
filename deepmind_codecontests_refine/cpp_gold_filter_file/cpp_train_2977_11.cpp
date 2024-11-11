#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
long long p[maxn] = {0};
void init() {
  for (int i = 2; i < maxn; i++) {
    if (p[i] != 0) continue;
    for (int j = i; j < maxn; j += i) p[j] = i;
  }
}
vector<long long> v;
int main() {
  ios::sync_with_stdio(false);
  init();
  long long N;
  long long K;
  cin >> N >> K;
  while (N != 1) {
    v.push_back(p[N]);
    N /= p[N];
  }
  if (v.size() < K) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; i < K; i++) {
    cout << v[i - 1] << ' ';
  }
  long long sum = 1;
  for (int i = K - 1; i < v.size(); i++) {
    sum *= v[i];
  }
  cout << sum << endl;
  return 0;
}
