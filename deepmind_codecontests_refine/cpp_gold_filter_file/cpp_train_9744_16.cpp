#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k, ans = 0;
  double soma = 0, media, aux;
  cin >> n >> k;
  vector<int> marks(n);
  for (int i = 0; i < n; i++) {
    cin >> marks[i];
    soma += marks[i];
  }
  media = soma / (double)n;
  aux = k - 0.5;
  while (media < aux) {
    ans++;
    n++;
    soma += k;
    media = soma / (double)n;
  }
  cout << ans << "\n";
}
