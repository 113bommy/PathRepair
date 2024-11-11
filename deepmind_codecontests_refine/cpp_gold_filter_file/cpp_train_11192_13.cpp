#include <bits/stdc++.h>
using namespace std;
long long a, b, arrA[200009], i, j, conta;
pair<long long, long long> arrB[200009], sol[200009];
int main() {
  cin >> a >> b;
  for (i = 0; i < a; ++i) cin >> arrA[i];
  for (i = 0; i < b; ++i) {
    cin >> arrB[i].first;
    arrB[i].second = i;
    sol[i].first = i;
  }
  sort(arrA, arrA + a);
  sort(arrB, arrB + b);
  j = 0;
  conta = 0;
  for (i = 0; i < b; ++i) {
    while (j < a and arrA[j] <= arrB[i].first) {
      ++conta;
      ++j;
    }
    sol[arrB[i].second].second = conta;
  }
  sort(sol, sol + b);
  j = 0;
  cout << sol[j].second;
  for (j = 1; j < b; ++j) cout << " " << sol[j].second;
  cout << endl;
  return 0;
}
