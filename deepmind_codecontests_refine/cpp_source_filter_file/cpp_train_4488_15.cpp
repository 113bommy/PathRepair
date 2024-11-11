#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> A(91, 0);
  for (int i = 0; s[i]; i++) {
    A[(int)s[i]]++;
  }
  for (int i = 65; i < 65 + k; i++)
    if (A[i] == 0) {
      cout << "0";
      return 0;
    }
  cout << 3 * (*min_element(A.begin() + 65, A.begin() + 65 + k));
  return 0;
}
