#include <bits/stdc++.h>
using namespace std;
vector<int> lis;
int seq[100010], indice[100010], cont[100010], contador[100010], n;
void solvelis() {
  for (int i = 0; i < n; i++) {
    int ind = lower_bound(lis.begin(), lis.end(), seq[i]) - lis.begin();
    if (ind == lis.size())
      lis.push_back(seq[i]);
    else
      lis[ind] = min(seq[i], lis[ind]);
    indice[i] = ind;
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> seq[i];
  solvelis();
  memset(cont, -1, sizeof cont);
  memset(contador, 0, sizeof contador);
  for (int i = n - 1; i >= 0; i--) {
    if (indice[i] == lis.size() - 1 ||
        (cont[indice[i] + 1] != -1 && seq[i] < cont[indice[i] + 1])) {
      cont[indice[i]] =
          (cont[indice[i]] == -1 ? seq[i] : min(cont[indice[i]], seq[i]));
      contador[indice[i]]++;
      indice[i]++;
    } else
      indice[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    if (indice[i]) {
      if (contador[indice[i] - 1] == 1)
        cout << "3";
      else
        cout << "2";
    } else
      cout << "1";
  }
  return 0;
}
