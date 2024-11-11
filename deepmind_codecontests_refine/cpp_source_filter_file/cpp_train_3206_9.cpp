#include <bits/stdc++.h>
using namespace std;

int main() {
  long A, B, K;
  cin >> A >> B >> K;
  cout << max(0, A - K) << "\n";
  cout << max(0, B + min(0, A - K)) << "\n";
}