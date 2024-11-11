#include <bits/stdc++.h>
using namespace std;
void OMG() { cout << "OMG>.< I don't know!\n"; }
void W1() { cout << "Freda's\n"; }
void W2() { cout << "Rainbow's\n"; }
bool ff1(string S) {
  string A = "";
  for (int i = 0; i < 5; i++) A += S[i];
  return (A == "miao.");
}
bool ff2(string S) {
  string A = "";
  for (int i = S.size() - 1 - 4; i < S.size(); i++) A += S[i];
  return (A == "lala.");
}
int main() {
  long long n, k;
  cin >> n >> k;
  if ((n * (n - 1)) / 2 <= k) {
    cout << "no solution\n";
    return 0;
  }
  long long x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    cout << x << ' ' << y << '\n';
    y++;
  }
  return 0;
}
