#include <bits/stdc++.h>
using namespace std;
long long m;
long long RES = 1;
vector<pair<int, int> > pts;
void cope(int s1, int s2) {
  int i2 = s2;
  for (int i = 1; i <= s1 + s2; i++) {
    long long j = i;
    while (!(j % 2) && i2) {
      j <<= 1;
      i2--;
    }
    RES = (RES * j) % m;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) {
    int j = i % n + 1;
    int c;
    scanf("%d", &c);
    pts.push_back(make_pair(c, j));
  }
  scanf("%I64d", &m);
  sort(pts.begin(), pts.end());
  pair<int, int> prev = make_pair(1000000010, 1000000010);
  int s1 = 0, s2 = 0;
  for (vector<pair<int, int> >::iterator it = pts.begin(); it != pts.end();
       it++) {
    if (it->first != prev.first) {
      cope(s1, s2);
      s1 = 1;
      s2 = 0;
    } else if (*it == prev) {
      s1--;
      s2++;
    } else
      s1++;
    prev = *it;
  }
  cope(s1, s2);
  printf("%I64d\n", RES);
}
