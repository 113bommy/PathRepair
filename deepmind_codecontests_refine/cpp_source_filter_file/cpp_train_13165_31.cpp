#include <bits/stdc++.h>
void sc(int &x) { scanf("%d", &x); }
void sc(long long int &x) { scanf("%lld", &x); }
void sc(char *x) { scanf("%s", x); }
void sc(double &x) { scanf("%lf", &x); }
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int p = n % 10;
  int q = n / 10;
  int ar[10] = {2, 4, 4, 3, 3, 4, 2, 5, 1, 2};
  cout << ar[p] * ar[q] << endl;
}
