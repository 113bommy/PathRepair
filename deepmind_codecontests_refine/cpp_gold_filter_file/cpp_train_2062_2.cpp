#include <bits/stdc++.h>
using namespace std;

int num_groups, p[100000], n, m, a, b, c;
int par(int x) { return (p[x]==x)? x:p[x]=par(p[x]); }
bool isSameGroup(int a, int b) { return par(a) == par(b); }
void merge(int a, int b) {
    num_groups -= (!isSameGroup(a, b));
    p[par(a)] = par(b);
}
                   
int main() {
  cin >> n >> m;
  for (int i=0; i<n; i++) p[i] = i;
  num_groups = n;
  for (int i=0; i<m; i++) {
    cin >> a >> b >> c;
    merge(a-1, b-1);
  }
  cout << num_groups;
}
