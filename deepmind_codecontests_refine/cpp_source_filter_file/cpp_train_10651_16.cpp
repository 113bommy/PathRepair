#include <bits/stdc++.h>
using namespace std;
int n;
struct {
  int taxi;
  int girl;
  int pizza;
  char name[21];
} a[101];
void show(int maxp, int maxg, int maxt) {
  int first = 1;
  cout << "If you want to call a taxi, you should call:";
  for (int i = 0; i < n; i++)
    if (maxt == a[i].taxi) {
      if (first--) {
        cout << " " << a[i].name;
        first--;
      } else
        cout << ", " << a[i].name;
    }
  printf(".");
  first = 1;
  cout << "\nIf you want to order a pizza, you should call:";
  for (int i = 0; i < n; i++)
    if (maxp == a[i].pizza) {
      if (first) {
        cout << " " << a[i].name;
        first--;
      } else
        cout << ", " << a[i].name;
    }
  printf(".");
  first = 1;
  cout << "\nIf you want to go to a cafe with a wonderful girl, you should "
          "call:";
  for (int i = 0; i < n; i++)
    if (maxg == a[i].girl) {
      if (first--) {
        cout << " " << a[i].name;
        first--;
      } else
        cout << ", " << a[i].name;
    }
  printf(".");
}
int main(int argc, char *argv[]) {
  int i, num, j, k;
  int maxg = 0, maxt = 0, maxp = 0;
  bool t, p;
  char tmp[21];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> num;
    cin >> a[i].name;
    a[i].taxi = 0;
    a[i].girl = 0;
    a[i].pizza = 0;
    for (j = 0; j < num; j++) {
      scanf(" %s", tmp);
      for (k = 3; tmp[k]; k++) tmp[k - 1] = tmp[k];
      tmp[k - 1] = 0;
      for (k = 5; tmp[k]; k++) tmp[k - 1] = tmp[k];
      tmp[k - 1] = 0;
      t = 1;
      p = 1;
      for (k = 1; tmp[k]; k++)
        if (tmp[k] != tmp[k - 1]) {
          t = 0;
        }
      if (!t) {
        for (k = 1; tmp[k]; k++)
          if (tmp[k] >= tmp[k - 1]) {
            p = 0;
          }
        if (p)
          a[i].pizza++;
        else
          a[i].girl++;
      } else {
        a[i].taxi++;
      }
    }
    maxp = (maxp > a[i].pizza ? maxp : a[i].pizza);
    maxg = (maxg > a[i].girl ? maxg : a[i].girl);
    maxt = (maxt > a[i].taxi ? maxt : a[i].taxi);
  }
  show(maxp, maxg, maxt);
  return 0;
}
