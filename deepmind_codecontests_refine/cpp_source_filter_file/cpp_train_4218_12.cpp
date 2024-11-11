#include <bits/stdc++.h>
using namespace std;
vector<long long int> v;
vector<char> item;
int ok;
void gcd(long long int a, long long int b, char c) {
  if (b == 0) {
    if (a != 1) {
      ok = 0;
    }
    return;
  }
  v.push_back((a - 1) / b);
  item.push_back(c);
  gcd(b, a % b, (1 - (c - 'A')) + 'A');
  return;
}
int main(void) {
  long long int x, y;
  scanf(" %lld %lld", &x, &y);
  ok = 1;
  if (x > y) {
    gcd(x, y, 'A');
  } else {
    gcd(y, x, 'B');
  }
  if (ok) {
    for (int i = 0; i < (int)v.size(); i++) {
      printf("%d%c", v[i], item[i]);
    }
    printf("\n");
  } else {
    printf("Impossible\n");
  }
  return 0;
}
