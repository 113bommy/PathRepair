#include <bits/stdc++.h>
using namespace std;
int main() {
  double N, K;
  cin >> N >> K;
  cout << floor(log(N - 1) / log(K) + 1) << endl;
}
