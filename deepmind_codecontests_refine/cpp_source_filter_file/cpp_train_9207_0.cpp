#include <bits/stdc++.h>
using namespace std;
const int N = 111;
string a[N], b[N];
vector<string> A[326], B[326];
int n;
int main() {
  cin >> n;
  for (int i = (1); i <= (n); i++) {
    a[i].resize(100);
    scanf("%s", &a[i][0]);
  }
  for (int i = (1); i <= (n); i++) {
    b[i].resize(100);
    scanf("%s", &b[i][0]);
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  for (int i = (n); i >= (1); i--) {
    A[(int)a[i][0]].push_back(a[i]);
    B[(int)b[i][0]].push_back(b[i]);
  }
  bool ppp = 0;
  for (int i = (0); i <= (300); i++) {
    while (A[i].size()) {
      if (ppp) printf(", ");
      ppp = 1;
      if (A[i].size() <= B[i].size()) {
        printf("%s %s", A[i].back().c_str(), B[i].back().c_str());
        A[i].pop_back();
        B[i].pop_back();
      } else {
        bool pp = 0;
        for (int j = (0); j <= (300); j++) {
          if (B[j].size() > B[i].size() || (j == i && B[j].size())) {
            pp = 1;
            printf("%s %s", A[i].back().c_str(), B[j].back().c_str());
            A[i].pop_back();
            B[j].pop_back();
            break;
          }
        }
      }
    }
  }
  return 0;
}
