#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int N;
  cin >> N;
  if (N == 2) {
    cout << 2;
    return 0;
  }
  int prev = 1;
  for (int i = 1; i < N; ++i) {
    int child = (prev + i) % N;
    prev = child;
    cout << child;
    if (i != N - 1) cout << " ";
  }
  return 0;
}
