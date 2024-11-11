#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  vector<long long int> a(m);
  for (int i = 0; i < m; i++) cin >> a[i];
  long long int ts = 0;
  for (int i = 0; i < m; i++) {
    vector<int> freq(5);
    for (int j = 0; j < n; j++) {
      freq[s[j][i] - 'A']++;
    }
    int max = 0;
    for (int p = 0; p < 5; p++) {
      if (freq[p] > max) {
        max = freq[p];
      }
    }
    ts += (max * a[i]);
  }
  cout << ts << endl;
}
