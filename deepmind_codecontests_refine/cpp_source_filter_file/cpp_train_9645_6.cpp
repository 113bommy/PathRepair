#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
const int INF = 1000000001;
int a[MAX];
int n, s, sum = 0;
int main() {
  int count = 0, temp;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> temp;
    a[temp] = temp;
  }
  for (int i = 1; i <= 101; ++i)
    if (a[i]) count++;
  cout << count << endl;
  return 0;
}
