#include <bits/stdc++.h>
using namespace std;
int numbers[300 + 1];
vector<int> prime;
void sieve() {
  int sqrtn = sqrt(300);
  for (int i = 2; i <= sqrtn; i++) {
    if (numbers[i] == 0) {
      for (int j = i; j <= 300; j += i) {
        numbers[j]++;
      }
    }
  }
}
int main() {
  sieve();
  int n;
  cin >> n;
  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    if (numbers[i] == 2) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
