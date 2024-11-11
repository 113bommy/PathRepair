#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200005;
int n, m;
set<pair<int, int> > odd;
set<pair<int, int> > even;
map<int, int> saveN;
vector<int> noa;
vector<int> nea;
int a[MAX_N];
int on, en;
vector<int> surplusE, surplusO, surplus;
bool changed[MAX_N] = {0};
void process() {
  int pointerO = 0;
  int pointerE = 0;
  int pointerS = 0;
  int pointerSO = 0;
  int pointerSE = 0;
  int res = 0;
  if (on > n / 2) {
    while (pointerSO < surplusO.size()) {
      if (pointerE < nea.size()) {
        a[surplusO[pointerSO]] = nea[pointerE];
        en++;
        pointerE++;
        pointerSO++;
        res++;
      } else {
        cout << -1 << endl;
        return;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (on == n / 2) break;
      if (a[i] & 1 && !changed[i]) {
        if (pointerE < nea.size()) {
          a[i] = nea[pointerE];
          en++;
          on--;
          pointerE++;
          res++;
        } else {
          cout << -1 << endl;
          return;
        }
      }
    }
  }
  if (en > n / 2) {
    while (pointerSE < surplusE.size()) {
      if (pointerO < noa.size()) {
        a[surplusE[pointerSE]] = noa[pointerO];
        on++;
        pointerO++;
        pointerSE++;
        res++;
      } else {
        cout << -1 << endl;
        return;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (en == n / 2) break;
      if (!(a[i] & 1) && !changed[i]) {
        if (pointerO < noa.size()) {
          a[i] = noa[pointerO];
          en--;
          on++;
          pointerO++;
          res++;
        } else {
          cout << -1 << endl;
          return;
        }
      }
    }
  }
  for (pointerSO; pointerSO < surplusO.size(); pointerSO++)
    surplus.push_back(surplusO[pointerSO]);
  for (pointerSE; pointerSE < surplusE.size(); pointerSE++)
    surplus.push_back(surplusE[pointerSE]);
  while (en != n / 2) {
    if (pointerE < nea.size()) {
      en++;
      a[surplus[pointerS]] = nea[pointerE];
      pointerS++;
      pointerE++;
    } else {
      cout << -1 << endl;
      return;
    }
  }
  while (on != n / 2) {
    if (pointerO < noa.size()) {
      on++;
      a[surplus[pointerS]] = noa[pointerO];
      pointerS++;
      pointerO++;
    } else {
      cout << -1 << endl;
      return;
    }
  }
  cout << surplus.size() + res << endl;
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int v = ++saveN[a[i]];
    if (v > 1) {
      if (a[i] & 1)
        surplusO.push_back(i);
      else
        surplusE.push_back(i);
      changed[i] = 1;
    } else if (v == 1) {
      on += (a[i] & 1);
      en += (1 - a[i] & 1);
    }
  }
  for (int i = 1; i <= min(n, m); i++)
    if (!saveN[i]) {
      if (i & 1)
        noa.push_back(i);
      else
        nea.push_back(i);
    }
  process();
  return 0;
}
