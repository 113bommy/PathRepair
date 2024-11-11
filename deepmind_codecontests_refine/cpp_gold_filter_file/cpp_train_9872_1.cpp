#include <bits/stdc++.h>
using namespace std;

int main() {
  int D, N;
  cin >> D >> N;

  if (N == 100) N++;
  cout << N * (int)pow(100, D) << endl;
}
