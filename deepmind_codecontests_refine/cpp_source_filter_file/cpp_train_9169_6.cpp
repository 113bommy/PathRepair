#include <bits/stdc++.h>
using namespace std;
int freq[101];
int main() {
  int n, x, max = 0, count = 0;
  cin >> n;
  string s;
  if (n == 1) {
    cin >> s;
    sort(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == s[i + 1]) count++;
    }
    cout << count << endl;
  } else if (n > 1) {
    int arr[101] = {};
    for (int i = 1; i <= n; i++) {
      cin >> x;
      freq[x]++;
    }
    for (int i = 1; i <= n; i++) {
      if (freq[i] > max) max = freq[i];
    }
    cout << max;
    return 0;
  }
}
