#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  scanf("%d", &N);
  int X = 0;
  for (int i = 0; i < N; i++) {
    cout << (char)(97 + X);
    if (X != 4)
      X += 1;
    else if (X == 4)
      X = 0;
  }
}
