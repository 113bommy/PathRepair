#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N;
  cin >> N;
  if (N % 2 == 0)
    cout << N / 2;
  else
    cout << (N + 1) / 2;
  return 0;
}
