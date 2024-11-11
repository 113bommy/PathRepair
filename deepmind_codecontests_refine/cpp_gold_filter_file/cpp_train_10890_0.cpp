#include <bits/stdc++.h>
using namespace std;
struct node {
  long long A, B;
};
bool func(node s1, node s2) { return s1.A < s2.A; }
int main() {
  long long n;
  cin >> n;
  std::vector<node> b(n);
  vector<long long> a(n);
  ;
  for (long long i = 0; i <= n - 1; i++) {
    cin >> a[i];
  }
  for (long long j = 0; j <= n - 1; j++) {
    cin >> b[j].A;
    b[j].B = j;
  }
  sort(b.begin(), b.end(), func);
  sort(a.begin(), a.end(), greater<int>());
  vector<long long> c(n);
  ;
  for (long long i = 0; i <= n - 1; i++) {
    c[b[i].B] = a[i];
  }
  for (long long i = 0; i <= n - 1; i++) {
    cout << c[i] << " ";
  }
  cout << endl;
  return 0;
}
