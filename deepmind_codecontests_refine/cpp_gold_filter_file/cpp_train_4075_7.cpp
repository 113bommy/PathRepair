#include <bits/stdc++.h>
using namespace std;
int freq[10001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    int t;
    cin >> t;
    freq[t]++;
  }
  int n1;
  for (int i = 10000; i >= 0; i--) {
    if (freq[i] != 0) {
      n1 = i;
      break;
    }
  }
  for (int i = 1; i * i <= n1; i++) {
    if (n1 % i == 0) {
      freq[i]--;
      if (i * i != n1) freq[n1 / i]--;
    }
  }
  cout << n1 << " ";
  for (int i = n1; i >= 0; i--) {
    if (freq[i] != 0) {
      cout << i;
      return 0;
    }
  }
}
