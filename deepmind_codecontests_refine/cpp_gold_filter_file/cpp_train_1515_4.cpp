#include <bits/stdc++.h>
using namespace std;
int main() {
  int aux, soma = 0, maival = 0;
  map<int, int> val;
  for (int i = 0; i < 5; i++) {
    cin >> aux;
    if (val.find(aux) == val.end())
      val.insert(make_pair(aux, 1));
    else {
      auto p = val.find(aux);
      (p->second)++;
    }
  }
  for (auto p = val.begin(); p != val.end(); p++) {
    soma += (p->second) * (p->first);
    if ((p->second) != 1) {
      int mult = (p->second);
      if ((p->second) > 3) mult = 3;
      int num = mult * (p->first);
      if (num > maival) maival = num;
    }
  }
  cout << soma - maival << endl;
  return 0;
}
