#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, H, W;
  cin >> N >> H >> W;
  cout << (N - W + 1) * (N - H + 1) << endl;
}