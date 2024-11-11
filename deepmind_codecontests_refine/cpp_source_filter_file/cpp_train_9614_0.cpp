#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long p[n];
  for (int i = 0; i < n; i++) cin >> p[i];
  long long r[5];
  for (int i = 0; i < 5; i++) cin >> r[i];
  int award[5] = {0, 0, 0, 0, 0};
  long long curr = 0;
  for (int i = 0; i < n; i++) {
    curr += p[i];
    for (int j = 4; j >= 0; j--) {
      award[j] += curr / r[j];
      curr = curr % r[j];
    }
  }
  for (int i = 0; i < 5; i++) cout << award[i] << " ";
  cout << endl;
  cout << curr << endl;
}
