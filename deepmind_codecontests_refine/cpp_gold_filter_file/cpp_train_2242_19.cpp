#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  string jump;
  cin >> jump;
  long long d[n];
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  bool visit[n];
  for (int i = 0; i < n; i++) {
    visit[i] = false;
  }
  long long p = 0;
  while (1) {
    if (visit[p] == true) {
      cout << "INFINITE";
      break;
    }
    visit[p] = true;
    if (jump[p] == '>') {
      p += d[p];
    } else {
      p -= d[p];
    }
    if (p < 0 || p > n - 1) {
      cout << "FINITE";
      break;
    }
  }
}
