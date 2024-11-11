#include <bits/stdc++.h>
using namespace std;
int main() {
  int p[4], a, b;
  for (int i = 0; i < 4; i++) cin >> p[i];
  cin >> a >> b;
  int count = 0;
  for (int i = a; i <= b && i < 1024; i++) {
    int numb = 0;
    for (int j = 0; j < 24; j++) {
      if ((((i % p[0]) % p[1]) % p[2]) % p[3] == i) numb++;
      next_permutation(p, p + 3);
    }
    if (numb >= 7) count++;
  }
  cout << count;
}
