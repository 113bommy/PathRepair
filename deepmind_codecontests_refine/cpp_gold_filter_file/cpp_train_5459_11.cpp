#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1024 * 1024;
long long N;
void print(int N) {
  if (N % 2 == 0)
    cout << N / 2 * N / 2 << endl;
  else
    cout << N / 2 * (N + 1) / 2 << endl;
  for (int i = 1; i <= (N / 2); i++)
    for (int j = N / 2 + 1; j <= N; j++) cout << i << " " << j << endl;
}
int main() {
  cin >> N;
  print(N);
  return 0;
}
