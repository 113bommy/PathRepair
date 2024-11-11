#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  int N2k = 0;
  int N2k1 = 0;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int t;
    cin >> t;
    if (t % 2 == 0)
      N2k++;
    else
      N2k1++;
  }
  if (N2k1 < N2k)
    cout << N2k1;
  else {
    while (N2k1 - 2 > N2k) {
      N2k1 -= 2;
      N2k++;
    }
    cout << N2k;
  }
}
