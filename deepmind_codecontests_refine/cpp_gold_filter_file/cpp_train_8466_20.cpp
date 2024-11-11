#include <bits/stdc++.h>
using namespace std;
long long cit[200], suit[200];
int main() {
  long long n, c;
  cin >> n >> c;
  long long res = 0;
  for (long long i = 0; i < n; i++) {
    cin >> suit[i] >> cit[i];
  }
  for (long long i = 1; 1; i++) {
    long long sum = 0;
    for (long long j = 0; j < n; j++) {
      sum += (1 + (i * suit[j]) / cit[j]);
    }
    if (sum == c) res++;
    if (sum > c) break;
  }
  cout << res << endl;
  return 0;
}
