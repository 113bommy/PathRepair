#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v) {
  cout << v.size() << "\n";
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  printf("\n");
}
int main() {
  int a, b, n, T, cas = 0;
  cin >> a >> b;
  int mx = a + b;
  int k = 1, s = 0;
  while (s + k <= mx) {
    s += k;
    k++;
  }
  k--;
  vector<int> A, B;
  for (int i = k; i >= 1; --i) {
    if (i <= a) {
      A.push_back(i);
      a -= i;
    } else {
      B.push_back(i);
      assert(b >= i);
      b -= i;
    }
  }
  print(A);
  print(B);
  return 0;
}
