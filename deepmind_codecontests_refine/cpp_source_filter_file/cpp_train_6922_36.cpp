#include <bits/stdc++.h>
using namespace std;
int arr1[100010], arr2[100010];
void solve() {
  int Na, Nb;
  cin >> Na >> Nb;
  int K, M;
  cin >> K >> M;
  for (int i = 0; i < Na; i++) cin >> arr1[i];
  for (int i = 0; i < Nb; i++) cin >> arr2[i];
  if (arr1[K - 1] < arr2[Nb - M - 1])
    cout << "YES\n";
  else
    cout << "NO\n";
  return;
}
int main() {
  solve();
  return 0;
}
