#include <bits/stdc++.h>
using namespace std;
mt19937 mt_rand(time(0));
int n, nrin = 59;
vector<int> v;
int intreaba(int x) {
  int ans;
  nrin--;
  cout << "> " << x << "\n";
  cout.flush();
  cin >> ans;
  if (ans == -1) exit(0);
  return ans;
}
int cauta(int st, int dr) {
  if (st <= dr) {
    int mijl = (st + dr) / 2;
    int ans = intreaba(mijl);
    if (ans == 1)
      return cauta(mijl + 1, dr);
    else
      return cauta(st, mijl - 1);
  } else
    return dr;
}
int cmmdc(int a, int b) {
  int r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main() {
  int x, dif, x1, maxi;
  cin >> n;
  maxi = cauta(0, 1e9);
  while (nrin > 0) {
    cout << "? " << (mt_rand()) % n + 1 << "\n";
    cout.flush();
    cin >> x;
    v.push_back(x);
    if (x == -1) exit(0);
    nrin--;
  }
  sort(v.begin(), v.end());
  dif = -1;
  for (int i = 2; i < v.size(); i++) {
    if (dif == -1) dif = v[i] - v[i - 1];
    if (v[i] != v[i - 1]) dif = cmmdc(dif, v[i] - v[i - 1]);
  }
  x1 = maxi - (n - 1) * dif;
  cout << "! " << x1 << " " << dif;
  cout.flush();
  return 0;
}
