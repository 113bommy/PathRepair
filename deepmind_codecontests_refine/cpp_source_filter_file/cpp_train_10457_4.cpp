#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  fast();
  int k, a, b;
  cin >> k >> a >> b;
  string s;
  cin >> s;
  int n = s.size();
  int l;
  if (n % k == 0) {
    l = n / k;
  } else {
    l = n / k + 1;
  }
  if (l >= a && l <= b) {
    int fr1 = n / k;
    int fr2 = n % k;
    fr1 = k - fr2;
    int p = 0;
    if (n % k && l == 1) {
      cout << "No solution";
      return 0;
    }
    for (int i = 0; i < fr1; i++) {
      for (int j = 0; j < n / k; j++, p++) cout << s[p];
      cout << "\n";
    }
    for (int i = 0; i < fr2; i++) {
      for (int j = 0; j <= n / k; j++, p++) cout << s[p];
      cout << "\n";
    }
  } else {
    cout << "No solution";
  }
}
