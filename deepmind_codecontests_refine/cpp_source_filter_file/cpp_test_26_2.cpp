#include <bits/stdc++.h>
using namespace std;
void factorial(int N) {
  const unsigned int L = 100000007;
  unsigned long long g = 1;
  for (int i = 3; i <= 2 * N; i++) g = (g * i) % L;
  cout << g << endl;
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    int N;
    cin >> N;
    factorial(N);
  }
}
