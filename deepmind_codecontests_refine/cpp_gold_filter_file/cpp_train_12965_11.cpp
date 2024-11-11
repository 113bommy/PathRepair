#include <bits/stdc++.h>
using namespace std;
int main() {
  set<long long> prime;
  long long i, j;
  long long f[101] = {0};
  for (i = 2; i < 50; i++) {
    if (f[i] == 1) continue;
    prime.insert(i);
    for (j = 2 * i; j < 101; j += i) {
      f[j] = 1;
    }
  }
  prime.insert(4);
  prime.insert(9);
  prime.insert(25);
  prime.insert(49);
  string y;
  long long c = 0;
  for (auto x : prime) {
    cout << x << endl;
    fflush(stdout);
    cin >> y;
    if (y == "yes") c++;
  }
  if (c > 1)
    cout << "composite";
  else
    cout << "prime";
  return 0;
}
