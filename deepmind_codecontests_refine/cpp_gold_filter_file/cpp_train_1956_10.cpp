#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,K;
  cin >> N >> K;
  cout << min(N % K, K - (N % K)) << endl;
}
