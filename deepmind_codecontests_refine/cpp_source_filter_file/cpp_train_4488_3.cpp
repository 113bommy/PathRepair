#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int count[26];
  for (int i = 0; i < n; i++) {
    count[s[i] - 'A']++;
  }
  int mini = *min_element(count, count + k);
  cout << mini * k;
  return 0;
}
