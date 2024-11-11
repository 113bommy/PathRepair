#include <bits/stdc++.h>
using namespace std;
int main() {
  long N, A, B;
  cin >> N >> A >> B;
  cout << N / (A + B) + min(A, N % (A + B)) << "\n";
}
