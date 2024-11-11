#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int strength;
vector<int> ans;
int jml;
int main() {
  scanf("%d %d %d", &n, &x, &y);
  int a = 1;
  int b = 1;
  double hasil1 = double(a) / double(x);
  double hasil2 = double(b) / double(y);
  while (fabs(hasil1 - hasil2) > 1e-15) {
    if (hasil1 < hasil2) {
      ans.push_back(0);
      a++;
    } else {
      ans.push_back(1);
      b++;
    }
    hasil1 = double(a) / double(x);
    hasil2 = double(b) / double(y);
  }
  ans.push_back(2);
  ans.push_back(2);
  jml = ans.size();
  while (n--) {
    scanf("%d", &strength);
    int apa = ans[(strength - 1) % jml];
    if (apa == 0)
      puts("Vanya");
    else if (apa == 1)
      puts("Vova");
    else
      puts("Both");
  }
  return 0;
}
