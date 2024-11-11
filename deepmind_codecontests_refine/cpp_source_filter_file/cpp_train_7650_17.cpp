#include <bits/stdc++.h>
using namespace std;
set<int> know;
set<int>::iterator it;
int main() {
  long long n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int j;
    for (j = 2; j < i; j++) {
      if (i % j == 0 && (i / j) % j != 0 && (i / j) > j) break;
    }
    know.insert(j);
  }
  cout << know.size() << endl;
  for (it = know.begin(); it != know.end(); it++) {
    cout << *it;
  }
}
