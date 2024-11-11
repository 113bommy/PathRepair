#include <bits/stdc++.h>
using namespace std;

int main() {
  long A, B, K;
  cin >> A >> B >> K;
  cout << max(0L, A - K) << "\n";
  cout << max(0L, B + min(0L, A - K)) << "\n";
}