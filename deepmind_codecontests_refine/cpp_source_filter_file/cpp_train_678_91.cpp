#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  if (N % 2 == 1 && N != 1)
    cout << (N - 1) / 2;
  else
    cout << (N - 1) / 2 + 1;
  return 0;
}
