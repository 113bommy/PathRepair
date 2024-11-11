#include <bits/stdc++.h>
using namespace std;
int main() {
  long long A, B, N;
  cin >> A >> B >> N;
  cout << A * min(A - 1, N) / B << endl;
}
