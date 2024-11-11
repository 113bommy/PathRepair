#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, K;
  cin >> A >> B >> K;
  for (int i = A; i <= B; i++) {
    if (i - A < K || B - i > K) cout << i << endl;
  }
}
