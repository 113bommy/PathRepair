#include <bits/stdc++.h>
using namespace std;
int numbers[3010 + 1];
vector<int> prime;
void sieve() {
  int sqrtn = sqrt(3010);
  for (int i = 2; i <= 3010; i++) {
    if (numbers[i] == 0) {
      for (int j = i; j <= 3010; j += i) {
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
