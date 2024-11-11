#include <iostream>

using namespace std;

const int MAX = 200000;

int main() {
  int M; cin >> M;
  int d[MAX];
  long long c[MAX];
  for (int i = 0; i < M; i++) cin >> d[i] >> c[i];

  long long D = 0;
  long long S = 0;
  for (int i = 0; i < M; i++) {
    S += d[i] * c[i];
    D += c[i];
  }

  long long ans = (D - 1) + (S - 1) / 9;

  cout << ans << endl;
}