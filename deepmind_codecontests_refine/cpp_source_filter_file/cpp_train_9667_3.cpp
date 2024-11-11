#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, w, c = 0;
  scanf("%d %d", &h, &w);
  vector<string> a(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
    for (auto x : a[i]) c += x == '#';
  }
  if (c == h + w - 1)
    printf("Possilble\n");
  else
    printf("Impossible\n");
}
