#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
const double EPS = 1e-6;
int prm[N], plm[N];
void prime() {
  for (int i = 2; i <= int(sqrt(N)); i++)
    if (!prm[i])
      for (int j = i + i; j < N; j += i) prm[j] = 1;
  for (int i = 2; i < N; i++) prm[i] = prm[i - 1] + 1 - prm[i];
}
void palindromic() {
  for (int i = 1; i < N; i++) {
    int x = i, y = 0;
    for (; x; x /= 10) y = y * 10 + x % 10;
    plm[i] = plm[i - 1] + (y == i);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  double p, q;
  cin >> p >> q;
  prime(), palindromic();
  for (int i = N - 1; i; i--)
    if (p / q * double(plm[i]) >= double(prm[i])) {
      cout << i << '\n';
      return 0;
    }
  cout << "Palindromic tree is better than splay tree\n";
  return 0;
}
