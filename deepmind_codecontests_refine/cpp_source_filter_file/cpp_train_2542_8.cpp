#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++) cin >> A[i];
  vector<int> v(A, A + n);
  sort(v.begin(), v.end());
  int piles = 0;
  vector<int>::iterator it;
  int blocks = 0;
  while (!v.empty()) {
    piles++;
    blocks = 0;
    for (it = v.begin(); it != v.end(); it++) {
      if (*it >= blocks) {
        blocks++;
        v.erase(v.begin());
        it--;
      }
    }
  }
  cout << piles << endl;
}
