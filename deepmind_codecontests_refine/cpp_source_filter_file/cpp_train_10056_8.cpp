#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int no[41];
  int rn[41];
  for (int i = 0; i <= 40; i++) {
    no[i] = 0;
    rn[i] = 0;
  }
  long long cv = 1;
  int noi = 0;
  int ctr = 0;
  long long nm;
  while (ctr < n) {
    cin >> nm;
    ctr++;
    while (nm >= (cv * 2)) {
      cv *= 2;
      noi++;
    }
    if (nm == cv && nm == 1) {
      no[noi]++;
      continue;
    }
    if (nm == cv && no[noi] < no[noi - 1]) {
      no[noi]++;
      continue;
    }
    rn[noi]++;
  }
  int nc = 0;
  int nen = 0;
  for (int i = 40; i >= 0; i--) {
    nc += no[i];
    nen += rn[i];
    if (nc < nen) {
      cout << -1 << endl;
      return 0;
    }
  }
  int mnn = no[0];
  int cn = 0;
  while (no[0] > 0) {
    cn++;
    int ic = 0;
    for (; ic <= 40; ic++) {
      if (no[ic] > 0) {
        no[ic]--;
        continue;
      }
      break;
    }
    ic--;
    bool jmu = 0;
    for (int i = ic; i >= 0; i--) {
      if (rn[i] > 0) {
        rn[i]--;
        jmu = 1;
        break;
      }
    }
    if (jmu) {
      continue;
    }
    if (!jmu) {
      if (no[0] == 0) {
        break;
      }
      for (ic = 0; ic <= 40; ic++) {
        no[ic]--;
        rn[ic]++;
        if (ic < 40 && no[ic] < no[ic + 1]) {
          continue;
        }
        break;
      }
    }
    rn[ic]--;
  }
  if (rn[0] > 0) {
    cn++;
  }
  for (int i = cn; i <= mnn; i++) {
    if (i > cn) {
      cout << " ";
    }
    cout << i;
  }
  cout << endl;
  cin >> n;
}
