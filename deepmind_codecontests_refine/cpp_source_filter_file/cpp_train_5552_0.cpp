#include <bits/stdc++.h>
using namespace std;
struct com {
  int a, b;
};
bool compare(com s, com s1) { return s.b > s1.b; }
bool compare1(com s, com s1) { return s.a > s1.a; }
int main() {
  int n, a1, b1;
  cin >> n;
  com ar[n];
  long long sum = 0;
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    cin >> a1 >> b1;
    ar[i].a = a1;
    ar[i].b = b1;
  }
  sort(ar, ar + n, compare);
  int j = 0;
  for (int i = 0; i < 4; i++) {
    if (ar[i].b == 0) {
      j = i;
      break;
    }
  }
  sort(ar + j, ar + n, compare1);
  for (int i = 0; i < n; i++) {
    if (cnt == 0) break;
    sum += ar[i].a;
    cnt -= 1;
    cnt += ar[i].b;
  }
  cout << sum;
}
