#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int mx = 1;
  for (int i = 2; i * i <= N; i++) {
    for (int j = 0; pow(i, j) <= N; j++) {
      mx = max(mx, (int) pow(i, j));
    }
  }
  cout << mx << "\n";
}