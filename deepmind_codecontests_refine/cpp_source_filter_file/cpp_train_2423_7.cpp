#include <bits/stdc++.h>
using namespace std;
void init() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
void printSet(int a, int b) { cout << -b << " " << a << " "; }
int arr[1000];
void input(int n) {
  for (int i = 0; i < n; i++) cin >> arr[i];
}
int main() {
  init();
  int q;
  cin >> q;
  for (int t = 0; t < q; t++) {
    int n;
    cin >> n;
    input(n);
    for (int i = 0; i < n / 2; i++) printSet(arr[i], arr[i + 1]);
    cout << "\n";
  }
}
