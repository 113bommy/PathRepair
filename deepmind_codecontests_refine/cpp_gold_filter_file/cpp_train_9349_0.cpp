#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll K, A, B;
  cin >> K >> A >> B;
  ll res;
  if (A+1 < B && K > A) {
    res = B + ((K - A - 1) / 2) * (B - A) + (K - A - 1) % 2;
  }
  else res = K + 1;
  cout << res << endl;
}
