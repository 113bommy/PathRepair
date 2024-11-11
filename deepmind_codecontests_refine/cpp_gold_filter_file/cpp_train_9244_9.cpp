#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int N, A, B, C, D, E;
  cin >> N >> A >> B >> C >> D >> E;
  long long int X = min({A, B, C, D, E});
  cout << (X + N - 1) / X + 4 << endl;
}
