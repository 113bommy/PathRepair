#include <bits/stdc++.h>
using namespace std;
int main() {
  bool first[100001];
  bool second[100001];
  memset(first, false, sizeof(first));
  memset(second, false, sizeof(second));
  unsigned long long int n, money;
  cin >> n >> money;
  for (int i = 0; i < n; i++) {
    unsigned long long int a;
    cin >> a;
    if (a > 100000) {
      second[a % 100000] = true;
    } else {
      first[a] = true;
    }
  }
  unsigned long long int count = 0;
  vector<unsigned long long int> chosen;
  for (unsigned long long int i = 1; i <= 1000000000; i++) {
    if (i > 100000) {
      if (second[i % 100000] == false) {
        if (money < i) break;
        count++;
        chosen.push_back(i);
        money = money - i;
      }
    } else {
      if (first[i] == false) {
        if (money < i) break;
        count++;
        chosen.push_back(i);
        money = money - i;
      }
    }
  }
  cout << count << "\n";
  for (unsigned long long int i = 0; i < count; i++) {
    cout << chosen[i] << " ";
  }
  return 0;
}
