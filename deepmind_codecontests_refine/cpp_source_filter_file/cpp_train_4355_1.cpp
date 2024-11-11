#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll N, K;
  cin >> N >> K;
  cout << (N - 1) / (K - 1) + ((N - 1) % (K - 1) == 0);
}
