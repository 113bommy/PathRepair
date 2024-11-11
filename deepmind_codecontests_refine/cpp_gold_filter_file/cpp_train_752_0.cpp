#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  string N, K, M;
  while (n) N += ((n % 3) + '0'), n /= 3;
  while (k) K += ((k % 3) + '0'), k /= 3;
  for (int i = 0; i < (int)N.size() - (int)K.size(); i++) K += '0', i--;
  for (int i = 0; i < (int)K.size() - (int)N.size(); i++) N += '0', i--;
  for (int i = 0; i < (int)N.size(); i++) {
    while (K[i] < N[i]) K[i] += 3;
    M += (K[i] - N[i]) + '0';
  }
  long long Ans = 0;
  for (int i = 0; i < (int)M.size(); i++) Ans += (M[i] - '0') * (pow(3, i));
  cout << Ans;
}
