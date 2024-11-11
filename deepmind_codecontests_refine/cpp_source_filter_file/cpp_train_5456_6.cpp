#include <bits/stdc++.h>
using namespace std;
long long sum = 0;
vector<int> x;
vector<vector<int> > graph;
vector<int> q;
vector<int> p;
int main() {
  int n, i;
  int sum = 0;
  int z = 0;
  scanf("%d\n", &n);
  for (i = 0; i < 2 * n; ++i) {
    double temp;
    char c;
    scanf("%c", &c);
    while (c != '.') {
      scanf("%c", &c);
    }
    int a = 0;
    scanf("%c", &c);
    a += (c - '0') * 100;
    scanf("%c", &c);
    a += (c - '0') * 10;
    scanf("%c", &c);
    a += (c - '0');
    scanf("%c", &c);
    sum += a;
    if (a != 0) z++;
  }
  int m = 10001;
  if (2 * z - 2 * n < 0)
    i = 0;
  else
    i = z - n;
  for (; i <= min(n, z); ++i) {
    if (abs(sum - i * 1000) < m) m = abs(sum - i * 1000);
  }
  sum = m;
  double b = double(sum) / 1000;
  printf("%.3f", b);
  return 0;
}
