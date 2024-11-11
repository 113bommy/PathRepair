#include <bits/stdc++.h>
using namespace std;
bool mark[10000000];
long X[2005];
long Y[2005];
int main() {
  int n;
  cin >> n;
  long a;
  for (int j = 0; j < n; j++) {
    cin >> a;
    mark[a] = true;
    X[j] = a;
  }
  for (int j = 0; j < n; j++) {
    cin >> a;
    mark[a] = true;
    Y[j] = a;
  }
  long z;
  long c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      z = X[i] ^ Y[j];
      if (mark[z]) c++;
    }
  }
  if (c % 2 == 0)
    cout << "Karen" << endl;
  else
    cout << "Koyomi" << endl;
}
