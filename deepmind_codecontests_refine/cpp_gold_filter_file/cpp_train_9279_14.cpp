#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, y;
  cin >> n >> x >> y;
  if (n > y) {
    cout << -1 << endl;
    return 0;
  }
  vector<long long int> seq1, seq2;
  long long int c1 = 0, c2 = 0;
  for (int i = 0; i < n - 1; i++) {
    seq1.push_back(1);
    c1 += 1;
    c2 += 1;
  }
  long long int s = y;
  seq1.push_back(s - c1);
  c1 += (s - c1) * (s - c1);
  c2 += (s - c2);
  if (c1 < x || c2 > y) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < seq1.size(); i++) cout << seq1[i] << " ";
  cout << endl;
}
