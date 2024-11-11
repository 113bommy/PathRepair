#include <bits/stdc++.h>
using namespace std;
int main() {
  int tableN;
  cin >> tableN;
  int* lengths = new int[tableN];
  int* energies = new int[tableN];
  int totalEnergy = 0;
  for (int i = 0; i < tableN; i++) {
    cin >> lengths[i];
  }
  for (int i = 0; i < tableN; i++) {
    cin >> energies[i];
    totalEnergy += energies[i];
  }
  for (int i = 0; i < tableN; i++) {
    lengths[i] = lengths[i] * 1000 + energies[i];
  }
  sort(lengths, lengths + tableN);
  for (int i = 0; i < tableN; i++) {
    energies[i] = lengths[i] % 1000;
    lengths[i] = lengths[i] / 1000;
  }
  int energyStore[201] = {0};
  int setS = 0;
  int sofarTotalE = 0;
  int ans = 20000000;
  bool flag = true;
  while (flag) {
    int energyStore2[201] = {0};
    int setNU = 0;
    int nextSetS;
    for (int i = setS; i < tableN; i++) {
      if (lengths[i] != lengths[setS]) {
        nextSetS = i;
        break;
      } else {
        ++setNU;
        ++energyStore2[energies[i]];
        sofarTotalE += energies[i];
      }
      if (i == tableN - 1) {
        flag = false;
      }
    }
    if (setNU > setS) {
      ans = min(ans, totalEnergy - sofarTotalE);
    } else {
      int countDown = setS - setNU + 1;
      int ans2 = totalEnergy - sofarTotalE;
      int k = 1;
      while (countDown) {
        if (energyStore[k]) {
          ans2 += min(energyStore[k], countDown) * k;
          countDown -= min(energyStore[k], countDown);
        }
        ++k;
      }
      ans = min(ans, ans2);
    }
    setS = nextSetS;
    for (int i = 1; i < 201; i++) {
      energyStore[i] += energyStore2[i];
    }
  }
  cout << ans << endl;
  return 0;
}
