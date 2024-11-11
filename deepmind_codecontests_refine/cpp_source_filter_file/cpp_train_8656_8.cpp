#include <bits/stdc++.h>
using namespace std;
int fx4[] = {1, -1, 0, 0};
int fy4[] = {0, 0, 1, -1};
int Kfx[] = {-2, -2, 2, 2, 1, 1, -1, -1};
int Kfy[] = {1, -1, 1, -1, 2, -2, 2, -2};
int fx8[] = {1, 1, 1, 0, 0, -1, -1, -1};
int fy8[] = {0, 1, -1, 1, -1, 0, 1, -1};
long long int BM(long long int a, long long int b, long long int m) {
  if (b == 0) return 1;
  long long int x = BM(a, b / 2, m);
  x = ((x % m) * (x % m)) % m;
  if (b % 2) x = ((x % m) * (a % m)) % m;
  return x;
}
int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    int n;
    scanf("%d", &n);
    string a;
    cin >> a;
    int plc = -1;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == '8') {
        plc = i;
        break;
      }
    }
    if (a.size() - 1 - plc >= 11 and plc != -1) {
      printf("YES\n");
    } else
      printf("NO\n");
  }
}
