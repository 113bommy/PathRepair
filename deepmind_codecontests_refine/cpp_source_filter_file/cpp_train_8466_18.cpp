#include <bits/stdc++.h>
using namespace std;
int cas[10011] = {0};
int peo[10011] = {0};
int n, c;
bool check(long long int x) {
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += (x * cas[i]) / peo[i] + 1;
  if (sum == c) return 1;
  return 0;
}
int main() {
  cin >> n >> c;
  for (int i = 0; i < n; i++) cin >> cas[i] >> peo[i];
  int count = 0;
  for (int i = 0; i <= 500000; i++) {
    if (check(i)) count++;
  }
  cout << count << endl;
  return 0;
}
