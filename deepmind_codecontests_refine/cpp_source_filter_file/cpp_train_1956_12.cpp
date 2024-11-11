#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  cout << min(N % K, K - (N % K)) << endl;
}
