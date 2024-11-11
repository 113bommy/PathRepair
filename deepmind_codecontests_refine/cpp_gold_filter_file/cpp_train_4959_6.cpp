#include <bits/stdc++.h>
using namespace std;
const int N = int(1e6) + 1;
int n;
vector<int> s, arr;
bool used[N];
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main(int argc, char *argv[]) {
  memset(used, false, sizeof(used));
  scanf("%d", &n);
  s.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &s[i]);
  }
  if (n == 1) {
    printf("1\n%d", s[0]);
    return 0;
  }
  int a = s[0];
  for (int i = 1; i < n; ++i) {
    a = gcd(a, s[i]);
  }
  if (s[0] != a) {
    printf("-1");
  } else {
    printf("%d\n", 2 * n - 1);
    printf("%d %d ", s[0], s[1]);
    for (int i = 2; i < n; ++i) {
      printf("%d %d ", s[0], s[i]);
    }
    printf("%d", s[0]);
  }
  return 0;
}
