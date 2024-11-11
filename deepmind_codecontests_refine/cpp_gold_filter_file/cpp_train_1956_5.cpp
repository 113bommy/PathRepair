#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, K;
  cin >> N >> K;
  cout << min(N % K, K - N % K) << "\n";
}