#include <bits/stdc++.h>
using namespace std;
struct house {
  int x, y, z;
};
struct wallpapers {
  int x, y, price;
};
vector<house> room;
vector<wallpapers> pap;
long long int Null = 18446744073709551610;
long long stoim(int i, int j) {
  if (pap[i].x < room[i].z)
    return Null;
  else {
    long long int p = 2 * room[i].x + 2 * room[i].y;
    long long int dl = (pap[j].y * (pap[j].x / room[i].z));
    return (p % dl == 0 ? p / dl * pap[j].price : (p / dl + 1) * pap[j].price);
  }
}
int main() {
  int n, m, i;
  cin >> n;
  room.resize(n);
  for (i = 0; i < n; ++i) cin >> room[i].x >> room[i].y >> room[i].z;
  cin >> m;
  pap.resize(m);
  for (i = 0; i < m; ++i) cin >> pap[i].x >> pap[i].y >> pap[i].price;
  long long int sum = 0, s, c;
  int j;
  for (i = 0; i < n; ++i) {
    j = 0;
    s = stoim(i, j);
    for (j = 1; j < m; ++j) {
      c = stoim(i, j);
      if (s > c) s = c;
    }
    sum += s;
  }
  cout << sum;
}
