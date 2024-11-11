#include <bits/stdc++.h>
using namespace std;
int cont[11];
int main() {
  string linha;
  int n, charc;
  cin >> n;
  for (int i = 0; i < 4; i++) {
    cin >> linha;
    for (int j = 0; j < 4; j++) {
      charc = linha[j] - 48;
      if (charc >= 1 && charc <= 9) cont[charc]++;
    }
  }
  int aperta = 1;
  for (int i = 0; i < 9; i++) {
    if (cont[i] > 2 * n) aperta = 0;
  }
  if (aperta == 0)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
