#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long int a[101];
long long int b[101];
int main() {
  long long int n, c = 0;
  ;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    long long int x, y;
    cin >> x >> y;
    a[x]++;
    b[y]++;
  }
  for (long long int i = 1; i < 101; i++) {
    if (a[i] > 0 && b[i] > 0) c += max(a[i], b[i]);
  }
  cout << c << '\n';
}
