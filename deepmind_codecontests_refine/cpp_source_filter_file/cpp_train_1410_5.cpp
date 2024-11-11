#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
set<int> s1, s2;
int p[N];
set<int> l, r;
int main() {
  int n;
  scanf("%d", &n);
  int arr[N];
  for (int i = 0; i < n; i++) scanf("%d", arr + i);
  s1.insert(arr[0]);
  s2.insert(-arr[0]);
  for (int i = 1; i < n; i++) {
    set<int>::iterator it1, it2;
    it1 = s1.upper_bound(arr[i]);
    it2 = s2.upper_bound(-arr[i]);
    int a = (int)1e9, b = -(int)1e9;
    if (it1 != s1.end()) b = *it1;
    if (it2 != s2.end()) a = *it2;
    a *= -1;
    if (a == -(int)1e9) a = b;
    if (b == -(int)1e9) b = a;
    if (a == b) {
      p[i] = a;
      if (p[i] > a)
        r.insert(a);
      else
        l.insert(a);
    } else {
      if (r.find(a) == r.end()) {
        r.insert(a);
        p[i] = a;
      } else {
        l.insert(b);
        p[i] = b;
      }
    }
    s1.insert(arr[i]);
    s2.insert(-arr[i]);
  }
  printf("%d", p[1]);
  for (int i = 2; i < n; i++) printf(" %d", p[i]);
  puts("");
  return 0;
}
