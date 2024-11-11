#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1000010;
long long A, B, C, Steps;
int main() {
  cin >> A >> B >> C;
  if (A <= 0 && B <= 0 && C > max(A, B)) {
    cout << "-1\n";
    return 0;
  }
  if (max(A, B) < C) {
    long long a, b;
    a = min(A, B);
    b = max(A, B);
    A = a, B = b;
    if (A < 0 && B > 0) {
      Steps += (-A) / B + 1;
      A += Steps * B;
    }
    a = min(A, B);
    b = max(A, B);
    A = a, B = b;
    while (max(A, B) < C) {
      A = A + B;
      swap(A, B);
      ++Steps;
    }
  }
  cout << Steps << '\n';
}
