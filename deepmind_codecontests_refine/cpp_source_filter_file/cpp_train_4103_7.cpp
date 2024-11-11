#include <bits/stdc++.h>
using namespace std;
struct no {
  int r;
  int l;
  int p;
};
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int dd[1100], ff[1100];
  int count = 0;
  for (int i = 0; i < n; i++) cin >> dd[i] >> ff[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - 1 - i; j++) {
      if (dd[j + 1] < dd[j]) {
        int y = dd[j];
        dd[j] = dd[j + 1];
        dd[j + 1] = dd[j];
        int u = ff[j];
        ff[j] = ff[j + 1];
        ff[j + 1] = u;
      } else if (ff[j + 1] < ff[j] && dd[j] == dd[j + 1]) {
        int y = dd[j];
        dd[j] = dd[j + 1];
        dd[j + 1] = dd[j];
        int u = ff[j];
        ff[j] = ff[j + 1];
        ff[j + 1] = u;
      }
    }
  for (int i = 0; i < n; i++) {
    int j = 0;
    for (j = 0; j < i; j++)
      if (dd[i] == dd[j]) {
        break;
      }
    if (j < i)
      continue;
    else {
      count += ff[i];
    }
  }
  if (count < k)
    cout << count << endl;
  else
    cout << k << endl;
  return 0;
}
