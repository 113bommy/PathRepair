#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> secret(4);
  for (int i = 0; i < 4; i++) {
    cin >> secret[i];
  }
  sort(secret.begin(), secret.end());
  int a = secret[1] - secret[0];
  int b = secret[2] - secret[0];
  int c = secret[3] - secret[0];
  printf("%d %d %d\n", a, b, c);
  return 0;
}
