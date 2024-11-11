#include <bits/stdc++.h>
using namespace std;
vector<char> hola;
int main() {
  int tam, total = 0;
  char a;
  cin >> tam;
  for (int i = 0; i < (tam); i++) {
    cin >> a;
    hola.push_back(a);
    total++;
    a -= '0';
    if ((int)a == 0) {
      cout << total << endl;
      return 0;
    }
  }
  cout << tam << endl;
  return 0;
}
