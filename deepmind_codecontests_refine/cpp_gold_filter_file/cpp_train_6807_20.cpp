#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  if (N % 2 == 0)
    cout << -1 << endl;
  else {
    for (int i = 0; i < N; i++) cout << i << (i == N - 1 ? '\n' : ' ');
    vector<int> V;
    V.push_back(0);
    for (int i = N - 2; i >= 1; i -= 2) V.push_back(i);
    for (int i = N - 1; i > 0; i -= 2) V.push_back(i);
    for (int i = 0; i < N; i++) cout << (V[i]) << (i == N - 1 ? '\n' : ' ');
    for (int i = 0; i < N; i++)
      cout << (V[i] + i) % N << (i == N - 1 ? '\n' : ' ');
  }
  return 0;
}
