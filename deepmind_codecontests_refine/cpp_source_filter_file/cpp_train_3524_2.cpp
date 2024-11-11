#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  long long P;
  cin >> N;
  P = 1;
  for (int i = 0; i < N; i++) {
    P = (P * i) % (1000000007);
  }
  cout << P;
}
