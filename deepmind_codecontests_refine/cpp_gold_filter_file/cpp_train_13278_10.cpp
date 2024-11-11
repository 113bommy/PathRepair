#include <bits/stdc++.h>
using namespace std;
char dem[45], a[10000000], b[10000000], c[10000], d[10000];
vector<int> a1;
int main() {
  int s, n;
  cin >> s;
  for (int i = 1; i < s; i++) {
    if (i % 2)
      cout << "I hate that ";
    else
      cout << "I love that ";
  }
  if (s % 2)
    cout << "I hate it";
  else
    cout << "I love it";
}
