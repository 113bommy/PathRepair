#include <bits/stdc++.h>
using namespace std;
int freq[1000] = {0};
int main() {
  int n;
  cin >> n;
  int p;
  cin >> p;
  for (int i = 0; i < p; ++i) {
    int temp;
    cin >> temp;
    freq[temp]++;
  }
  cin >> p;
  for (int i = 0; i < p; ++i) {
    int temp;
    cin >> temp;
    freq[temp]++;
  }
  for (int i = 1; i <= n; ++i) {
    if (freq[i] == 0) {
      cout << "Oh, my keyboard!";
      return 0;
    }
  }
  cout << "I become the guy.";
  return 0;
}
