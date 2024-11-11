#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
int ctr = 0;
int db[N];
int nu[N];
long long sum = 0;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int r;
    cin >> r;
    db[r]++;
    if (db[r] == 1) {
      sum += ctr;
      ctr++;
      nu[r] = ctr;
    } else {
      sum += ctr - nu[r];
      if (db[r] == 2) sum++;
      nu[r] = ctr;
    }
  }
  cout << sum;
}
