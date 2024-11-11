#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int chores[2000];
int main() {
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> chores[i];
  }
  sort(chores, chores + n);
  cout << chores[a] - chores[a - 1] << '\n';
}
