#include <bits/stdc++.h>
using namespace std;
bool happyg[110] = {};
bool happyb[110] = {};
int main() {
  int N, M;
  cin >> N >> M;
  int B, G;
  cin >> B;
  int b, g;
  for (int i = 0; i < B; i++) {
    cin >> b;
    happyb[b] = true;
  }
  cin >> G;
  for (int i = 0; i < G; i++) {
    cin >> g;
    happyg[g] = true;
  }
  for (int i = 0; i < N * M; i++) {
    bool t = happyb[i % N] | happyg[i % M];
    happyb[i % N] = t;
    happyg[i % M] = t;
  }
  bool happy = true;
  for (int i = 0; i < N; i++) {
    happy &= happyb[i];
  }
  for (int i = 0; i < M; i++) {
    happy &= happyg[i];
  }
  if (happy) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
