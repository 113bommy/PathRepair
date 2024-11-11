#include <bits/stdc++.h>
using namespace std;
int hely[2000003];
int eler[2000003][3];
bool valt[2000003][3];
bool blokk[2000003][3];
int n, m1, m2, t;
vector<int> sor1, sor2;
vector<pair<int, int> > loves;
vector<int> sorvalt;
int DB = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m1 >> m2 >> t;
  sor1.resize(m1);
  sor2.resize(m2);
  for (int i = 0; i < m1; i++) {
    cin >> sor1[i];
  }
  for (int i = 0; i < m2; i++) {
    cin >> sor2[i];
  }
  int tart1 = 0, tart2 = 0;
  hely[0] = 0;
  DB++;
  while (tart1 < sor1.size() && tart2 < sor2.size()) {
    if (hely[DB] == sor1[tart1] && hely[DB] == sor2[tart2]) {
      blokk[DB][1] = true;
      blokk[DB][2] = true;
      DB++;
      hely[DB] = hely[DB - 1] + 1;
      tart1++;
      tart2++;
    } else if (hely[DB] == sor1[tart1]) {
      blokk[DB][1] = true;
      DB++;
      hely[DB] = hely[DB - 1] + 1;
      tart1++;
    } else if (hely[DB] == sor2[tart2]) {
      blokk[DB][2] = true;
      DB++;
      hely[DB] = hely[DB - 1] + 1;
      tart2++;
    } else if (sor1[tart1] == sor2[tart2]) {
      DB++;
      hely[DB] = sor1[tart1];
      blokk[DB][1] = blokk[DB][2] = true;
      DB++;
      hely[DB] = sor1[tart1] + 1;
      tart1++;
      tart2++;
    } else if (sor1[tart1] < sor2[tart2]) {
      DB++;
      hely[DB] = sor1[tart1];
      blokk[DB][1] = true;
      DB++;
      hely[DB] = sor1[tart1] + 1;
      tart1++;
    } else {
      DB++;
      hely[DB] = sor2[tart2];
      blokk[DB][2] = true;
      DB++;
      hely[DB] = sor2[tart2] + 1;
      tart2++;
    }
  }
  while (tart1 < sor1.size()) {
    if (hely[DB] == sor1[tart1]) {
      blokk[DB][1] = true;
      tart1++;
    } else {
      DB++;
      hely[DB] = sor1[tart1];
      blokk[DB][1] = true;
      DB++;
      hely[DB] = sor1[tart1] + 1;
      tart1++;
    }
  }
  while (tart2 < sor2.size()) {
    if (hely[DB] == sor2[tart2]) {
      blokk[DB][2] = true;
      tart2++;
    } else {
      DB++;
      hely[DB] = sor2[tart2];
      blokk[DB][2] = true;
      DB++;
      hely[DB] = sor2[tart2] + 1;
      tart2++;
    }
  }
  if (hely[DB] != n + 1) {
    DB++;
    hely[DB] = n + 1;
  }
  eler[0][2] = -1;
  for (int i = 1; i <= DB; i++) {
    if (eler[i - 1][1] >= 0)
      eler[i][1] = eler[i - 1][1] + hely[i] - hely[i - 1];
    else
      eler[i][1] = -1;
    if (blokk[i][1]) {
      if (eler[i][1] > t)
        eler[i][1] -= t;
      else
        eler[i][1] = -1;
    }
    if (eler[i - 1][2] >= 0)
      eler[i][2] = eler[i - 1][2] + hely[i] - hely[i - 1];
    else
      eler[i][2] = -1;
    if (blokk[i][2]) {
      if (eler[i][2] > t)
        eler[i][2] -= t;
      else
        eler[i][2] = -1;
    }
    if (!blokk[i][1] && min(t, eler[i][2]) > eler[i][1]) {
      valt[i][1] = true;
      eler[i][1] = min(t, eler[i][2]);
    }
    if (!blokk[i][2] && min(t, eler[i][1]) > eler[i][2]) {
      valt[i][2] = true;
      eler[i][2] = min(t, eler[i][1]);
    }
  }
  if (eler[DB][1] >= 0) {
    int z = 1;
    int utolsoloves = n + t + 100;
    while (DB > 0) {
      if (valt[DB][z]) {
        sorvalt.push_back(hely[DB]);
        z = 3 - z;
      } else {
        if (blokk[DB][z]) {
          utolsoloves = min(utolsoloves - t, hely[DB] - 1);
          loves.push_back({utolsoloves, z});
        }
        DB--;
      }
    }
    cout << "Yes" << endl;
    cout << sorvalt.size() << endl;
    for (int i = sorvalt.size() - 1; i >= 0; i--) cout << sorvalt[i] << " ";
    cout << endl << loves.size() << endl;
    for (int i = loves.size() - 1; i >= 0; i--)
      cout << loves[i].first << " " << loves[i].second << '\n';
  } else
    cout << "No" << endl;
}
