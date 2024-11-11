#include <bits/stdc++.h>
using namespace std;
void pairsort(int a[], int b[], int x) {
  pair<int, int> pairt[x];
  for (int i = 0; i < x; i++) {
    pairt[i].first = a[i];
    pairt[i].second = b[i];
  }
  sort(pairt, pairt + x);
  for (int i = 0; i < x; i++) {
    a[i] = pairt[i].first;
    b[i] = pairt[i].second;
  }
}
int main() {
  int n, m, arr[100000], brr[100000];
  cin >> n >> m;
  int strength = n, cnt = 0;
  for (int i = 0; i < m; i++) {
    cin >> arr[i] >> brr[i];
  }
  pairsort(arr, brr, m);
  if (arr[0] >= n) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 0; i < m; i++) {
    strength += brr[i];
    if (strength > arr[i + 1]) {
      cnt++;
    }
  }
  if (cnt == m)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
