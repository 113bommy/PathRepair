#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int> a;
  int n, num;
  scanf("%d", &n);
  for (int i = (int)0; i < (int)n; ++i) {
    scanf("%d", &num);
    a[num]++;
  }
  int count = 0, last;
  for (typeof(a.begin()) i = a.begin(); i != a.end(); i++) {
    count += i->second % 2;
    last = i->first;
    if (i->second > 1) a[i->first + 1] += i->second / 2;
  }
  cout << last - count + 1 << "\n";
  return 0;
}
