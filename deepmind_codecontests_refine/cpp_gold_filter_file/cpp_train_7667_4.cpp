#include <bits/stdc++.h>
using namespace std;
const int LN = 1e3 + 5;
int N, res;
string palabra;
bool letra[LN][30], memo[LN];
bool iguales;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> palabra;
    for (int j = 0, tam = palabra.size(); j < tam; j++)
      letra[i][palabra[j] - 'a'] = true;
  }
  res = N;
  for (int i = 0; i < N; i++) {
    if (memo[i]) continue;
    for (int j = i + 1; j < N; j++) {
      iguales = true;
      for (int k = 0; k <= 'z' - 'a'; k++) {
        if (letra[i][k] != letra[j][k]) {
          iguales = false;
          break;
        }
      }
      if (iguales) {
        res--;
        memo[j] = true;
      }
    }
  }
  cout << res;
  return 0;
}
