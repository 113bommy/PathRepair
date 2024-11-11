#include <bits/stdc++.h>
using namespace std;
struct neg {
  short int a, b;
};
bool comp(const neg &a, const neg &b) {
  return (a.a + a.b > b.a + b.b || a.a + a.b == b.a + b.b && a.a < b.a);
}
int main() {
  short int n, negN = 0;
  int score;
  scanf("%hi%i", &n, &score);
  map<short int, short int> POS;
  neg NEG[100];
  for (int i = 0; i < n; i++) {
    short int a, b;
    scanf("%hi%hi", &a, &b);
    if (b >= 0)
      POS.insert(make_pair(a, b));
    else {
      neg NegR;
      NegR.a = a;
      if (-b > a) NegR.a = -b;
      NegR.b = b;
      NEG[negN++] = NegR;
    }
  }
  sort(NEG, NEG + negN, comp);
  for (auto it : POS) {
    if (score < it.first) return 0 * printf("NO");
    score += it.second;
  }
  for (short int i = 0; i < negN; i++) {
    if (score < NEG[i].a) return 0 * printf("NO");
    score += NEG[i].b;
  }
  printf("YES");
}
