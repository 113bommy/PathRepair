#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n;
  vector<int> v;
  cout << "? " << 1 << ' ' << 2 << endl;
  cin >> k;
  int AplusB = k;
  cout << "? 1 3" << endl;
  cin >> k;
  int AplusBplusC = k;
  cout << "? 2 3" << endl;
  cin >> k;
  int BplusC = k;
  int A = AplusBplusC - BplusC;
  int B = AplusBplusC - AplusB;
  int C = AplusBplusC - A - B;
  v.push_back(A);
  v.push_back(B);
  v.push_back(C);
  int sumto = A + B + C;
  for (int i = 4; i <= n; i++) {
    cout << "? " << 1 << ' ' << i << endl;
    cin >> k;
    v.push_back(k - sumto);
    sumto += k - sumto;
  }
  cout << "! ";
  for (int i : v) cout << i << ' ';
  cout << endl;
  return 0;
}
