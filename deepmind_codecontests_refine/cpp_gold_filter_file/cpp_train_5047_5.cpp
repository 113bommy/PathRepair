#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, w;
  cin >> l >> w;
  if (l < w) swap(l, w);
  long long count = 0;
  while (l > 0 && w > 0) {
    count += l / w;
    l = l % w;
    if (l < w) swap(l, w);
  }
  cout << count << endl;
}
