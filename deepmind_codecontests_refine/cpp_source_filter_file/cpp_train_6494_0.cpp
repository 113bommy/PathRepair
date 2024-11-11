#include <bits/stdc++.h>
using namespace std;
int i;
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  };
  string hq;
  cin >> hq;
  int q = 0;
  int hp = 0;
  int N = hq.length();
  for (int i = 0; i < N; i++) {
    if (hq[i] == 'Q') q++;
  }
  double Q = double(q);
  Q = sqrt(Q);
  bool result = (Q == int(sqrt(double(q))));
  if (result) {
    if (q == 0) {
      cout << "YES" << endl;
      return 0;
    }
    q = int(Q);
    bool first_q = false;
    for (int i = 0; i < N; i++) {
      if (hq[i] == 'Q') {
        hp = i;
        break;
      }
    }
    int licz = 0;
    int hkoniec = 0;
    for (int i = 0; i < N; i++) {
      if (hq[i] == 'Q') licz++;
      if (licz == q * q) {
        if (hq[i] == 'H') hkoniec++;
      }
    }
    if (hp % 2 != 1 && (hkoniec % 2 != 1)) {
      string wzorzec = "";
      licz = 0;
      bool escape = true;
      int koniec = hq.length() - 1;
      for (int i = hp / 2; i < koniec + 1; i++) {
        if (hq[i] == 'Q') licz++;
        if (licz == q && escape) {
          koniec = i + hkoniec / 2;
          escape = false;
        }
        wzorzec.insert(wzorzec.end(), hq[i]);
      }
      string wyraz = "";
      int M = wzorzec.length();
      for (int i = 0; i < M; i++) {
        if (wzorzec[i] == 'H') {
          wyraz.insert(wyraz.end(), 'H');
        } else
          wyraz += wzorzec;
      }
      for (int i = 0; i < N; i++) {
        if (wyraz[i] != hq[i]) {
          cout << "NO";
          return 0;
        }
      }
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  } else
    cout << "NO" << endl;
}
