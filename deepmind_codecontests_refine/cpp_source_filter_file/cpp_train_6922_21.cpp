#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[100001];
  int b[100001];
  int k;
  int m;
  int na;
  int nb;
  cin >> na >> nb;
  cin >> k >> m;
  for (int i = 0; i < na; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < nb; i++) {
    cin >> b[i];
  }
  if (a[k - 1] < b[nb - 1])
    cout << "YES";
  else
    cout << "NO";
}
