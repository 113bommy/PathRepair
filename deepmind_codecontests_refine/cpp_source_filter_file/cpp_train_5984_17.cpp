#include <bits/stdc++.h>
using namespace std;
char x[100100];
long long fr[300], a[100100], pp;
int i;
ifstream f("t.in");
void Inmulteste(int x) {
  int i;
  for (i = 1; i <= a[0]; ++i) {
    a[i] = a[i] + x;
    x = a[i] / 10;
    a[i] %= 10;
  }
  while (x) a[++a[0]] = x % 10, x /= 10;
}
int main() {
  cin.getline(x, 100100);
  for (i = 0; x[i] != '\0'; ++i) ++fr[x[i]];
  for (i = 0; i < 300; ++i) fr[i] *= fr[i];
  a[1] = a[0] = 0;
  for (i = 0; i < 300; ++i)
    if (fr[i]) Inmulteste(fr[i]);
  for (i = a[0]; i > 0; --i) cout << a[i];
  cout << "\n";
  return 0;
}
