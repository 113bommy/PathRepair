#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int a00, a01, a10, a11;
  cin >> a00 >> a01 >> a10 >> a11;
  vector<long long> gen(1e6 + 1);
  int i;
  gen[0] = 0;
  gen[1] = 0;
  int z = 0;
  int w = 0;
  for (i = 2; i <= 1e6; i++) {
    gen[i] = i - 1 + gen[i - 1];
  }
  auto it1 = lower_bound(gen.begin(), gen.end(), a00);
  if (it1 == gen.end() || *it1 != a00) {
    cout << "Impossible";
    return 0;
  }
  z = it1 - gen.begin();
  auto it2 = lower_bound(gen.begin(), gen.end(), a11);
  if (it2 == gen.end() || *it2 != a11) {
    cout << "Impossible";
    return 0;
  }
  w = it2 - gen.begin();
  if (a00 == 0 && a11 == 0) {
    if (a01 == 0 && a10 == 0) {
      cout << "1";
    } else if (a01 == 1 && a10 == 0) {
      cout << "01";
    } else if (a10 == 1 && a01 == 0) {
      cout << "10";
    } else {
      cout << "Impossible";
    }
    return 0;
  } else if (a00 == 0) {
    z = (a01 + a10);
    if (z % w == 0) {
      z = z / w;
    } else {
      cout << "Impossible";
      return 0;
    }
    if (z > 1) {
      cout << "Impossible";
      return 0;
    }
  } else if (a11 == 0) {
    w = (a01 + a10);
    if (w % z == 0) {
      w = w / z;
    } else {
      cout << "Impossible";
      return 0;
    }
    if (w > 1) {
      cout << "Impossible";
      return 0;
    }
  }
  long long cross = w * z;
  if (a01 + a10 != cross) {
    cout << "Impossible";
    return 0;
  }
  long long b01 = cross;
  long long b10 = 0;
  string str(w + z, '1');
  for (i = 0; i < z; i++) {
    str[i] = '0';
  }
  int curr = z - 1;
  int limit = str.length();
  while (b01 != a01 && b10 != a10) {
    int shift = (int)min(a10 - b10, limit - (long long)1 - curr);
    str[curr] = '1';
    str[curr + shift] = '0';
    limit = curr + shift;
    b10 += shift;
    b01 -= shift;
    curr--;
  }
  cout << str;
  return 0;
}
