#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K; cin >> N >> K;
  cout << ((K == 1) ? 0 : N - K) << endl;
}