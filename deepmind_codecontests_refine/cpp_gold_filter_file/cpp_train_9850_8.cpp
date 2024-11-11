#include <bits/stdc++.h>
using namespace std;
long long y[2000];
bool used[2000];
vector<int> no;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &y[i]);
  }
  for (int p = 0; p < 3; p++) {
    for (int i = 0; i < n; i++) {
      used[i] = false;
    }
    no.clear();
    int i1 = p % 3, i2 = (p + 1) % 3;
    long long a = y[i1] - y[i2];
    long long b = i2 - i1;
    long long c = -a * i1 - b * y[i1];
    for (int i = 0; i < n; i++) {
      if (a * i + b * y[i] + c != 0) {
        no.push_back(i);
        used[i] = true;
      }
    }
    if (no.size() == 1) {
      printf("Yes");
      return 0;
    } else if (no.size() > 1) {
      long long aa = y[no[0]] - y[no[1]];
      long long bb = no[1] - no[0];
      long long cc = -aa * no[0] - bb * y[no[0]];
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if (aa * i + bb * y[i] + cc != 0 && used[i]) {
          ok = false;
        }
      }
      if (ok && b * aa == a * bb) {
        printf("Yes");
        return 0;
      }
    }
  }
  printf("No");
  return 0;
}
