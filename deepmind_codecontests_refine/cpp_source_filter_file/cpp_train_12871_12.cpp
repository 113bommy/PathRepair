#include <bits/stdc++.h>
using namespace std;
bool vis[1000007];
void seive() {
  for (int i = 4; i <= 1000000; i += 2) vis[i] = true;
  for (int i = 3; i * i <= 1000000; i++) {
    for (int j = i + i; j <= 1000000; j += i) {
      vis[j] = true;
    }
  }
  vis[1] = true;
}
int main() {
  seive();
  long long N, E, sum;
  cin >> N >> E;
  for (int i = N;; i++) {
    if (vis[i] == false) {
      sum = i;
      break;
    }
  }
  cout << 2 << " " << sum << endl;
  cout << 1 << " " << N << " 2" << endl;
  E--;
  sum -= 2;
  for (int i = 2; i <= N - 2; i++) {
    cout << 1 << " " << i << " " << 1 << endl;
    sum--;
    E--;
  }
  if (N > 2) {
    cout << 1 << " " << N - 1 << " " << sum << endl;
    E--;
  }
  for (int i = 2; i <= N; i++) {
    if (E <= 0) break;
    for (int j = i + 1; j <= N; j++) {
      cout << i << " " << j << " " << 10000000000 << endl;
      E--;
      if (E < 1) break;
    }
  }
  return 0;
}
