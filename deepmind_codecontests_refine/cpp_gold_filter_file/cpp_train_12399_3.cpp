#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  long long v;
  vector<long long> veca, vecb;
  for (int i = 0; i < n; i++) {
    cin >> v;
    veca.push_back(v);
  }
  for (int i = 0; i < n; i++) {
    cin >> v;
    vecb.push_back(v);
  }
  sort(veca.rbegin(), veca.rend());
  sort(vecb.rbegin(), vecb.rend());
  long long a = 0, b = 0;
  int i = 0, j = 0, t = 0;
  while (i != n && j != n) {
    long long f = veca[i];
    long long s = vecb[j];
    if (t % 2 == 0) {
      if (f >= s) {
        a += f;
        i++;
      } else {
        j++;
      }
    } else {
      if (s >= f) {
        b += s;
        j++;
      } else {
        i++;
      }
    }
    t++;
  }
  if (i != n && j == n) {
    for (int k = i; k < n; k++) {
      if (t % 2 == 0) {
        a += veca[k];
      }
      t++;
    }
  } else if (i == n && j != n) {
    for (int k = j; k < n; k++) {
      if (t % 2 == 1) {
        b += vecb[k];
      }
      t++;
    }
  }
  cout << a - b << '\n';
  return 0;
}
