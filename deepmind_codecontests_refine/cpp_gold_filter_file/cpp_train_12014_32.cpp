#include <bits/stdc++.h>
using namespace std;
bool flag[10000010];
vector<long long int> v;
void seive() {
  flag[1] = true;
  for (long long int i = 4; i < 10000010; i += 2) {
    flag[i] = true;
  }
  for (long long int i = 3; i * i <= 10000010; i += 2) {
    if (!flag[i]) {
      for (long long int j = i * i; j < 10000010; j += 2 * i) {
        flag[j] = true;
      }
    }
  }
  for (long long int i = 1; i < 10000010; i++)
    if (!flag[i]) v.push_back(i);
  return;
}
int main() {
  seive();
  long long int n;
  cin >> n;
  for (long long int i = 0; i < n; i++) cout << v[i] << " ";
  return 0;
}
