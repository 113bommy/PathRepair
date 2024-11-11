#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main(int argc, char **argv) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  long long t = K;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    t = gcd(t, x % K);
  }
  set<int> S;
  for (int i = 0; i < K; i++) S.insert(i * t % K);
  cout << S.size() << '\n';
  for (auto it = S.begin(); it != S.end(); it++) cout << *it << " ";
  cout << endl;
  return 0;
}
