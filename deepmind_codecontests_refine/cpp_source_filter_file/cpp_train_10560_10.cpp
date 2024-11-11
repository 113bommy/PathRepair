#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int arr[105];
int isPoint[105];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int x[n];
  for (int i = 0, tmp; i < n; i++) {
    cin >> tmp;
    x[i] = tmp;
    isPoint[tmp] = 1;
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
  }
  for (int i = 0, c = 0; i < 100; i++) {
    if (isPoint[i]) arr[i] = c, c = !c;
  }
  for (int tmp : x) cout << arr[tmp] << " ";
}
