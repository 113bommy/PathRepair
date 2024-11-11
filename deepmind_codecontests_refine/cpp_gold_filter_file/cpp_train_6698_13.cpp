#include <bits/stdc++.h>
using namespace std;
struct node {
  int a;
  int b;
};
bool com(node x, node y) { return (x.a < y.a); }
struct node nod[100000];
int main() {
  int t = 1, i, n;
  while (t--) {
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> nod[i].a;
    }
    for (i = 0; i < n; i++) {
      cin >> nod[i].b;
    }
    sort(nod, nod + n, com);
    for (i = 0; i < n; i++) {
      cout << nod[i].b << " ";
    }
    cout << "\n";
  }
  return 0;
}
