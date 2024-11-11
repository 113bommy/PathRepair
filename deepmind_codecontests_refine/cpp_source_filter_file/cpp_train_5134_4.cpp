#include <bits/stdc++.h>
using namespace std;
long long int Composite[10000000];
long long int sF(long long int N) {
  if (N == 2) return 0;
  if ((N & 1) == 0) return 2;
  if (N < 10000000) return Composite[N];
  for (long long int i = 3; i * i < N; i += 2) {
    if (Composite[i] != 0) continue;
    if (N % i == 0) return i;
  }
  return 0;
}
int main(void) {
  for (int i = 3; i * i < 10000000; i += 2) {
    if (Composite[i] != 0) continue;
    for (int j = 3 * i; j < 10000000; j += (i << 1)) {
      if (Composite[j] == 0) Composite[j] = i;
    }
  }
  long long int i, N;
  cin >> N;
  if (sF(N) == 0)
    cout << "1" << endl << "0";
  else {
    if (sF(N / sF(N)) == 0)
      cout << "2";
    else {
      cout << "1" << endl;
      cout << sF(N) * sF(N / sF(N));
    }
  }
  return 0;
}
