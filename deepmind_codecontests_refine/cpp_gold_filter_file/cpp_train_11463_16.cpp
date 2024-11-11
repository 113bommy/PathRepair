#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  long long i = 1;
  while (i * (i + 1) / 2 <= a + b) {
    i++;
  }
  i--;
  long long sum = (i) * (i + 1) / 2;
  vector<long long> p;
  vector<long long> q;
  vector<bool> used(i, false);
  for (long long j = i; j >= 1; j--) {
    if (a >= j) {
      a -= j;
      used[j - 1] = true;
      p.push_back(j);
    } else if (a < i && a > 0) {
      used[a - 1] = true;
      p.push_back(a);
      a -= a;
    } else {
      break;
    }
  }
  for (long long j = 0; j < i; j++) {
    if (!used[j]) {
      q.push_back(j + 1);
    }
  }
  cout << p.size() << endl;
  for (long long num : p) {
    cout << num << " ";
  }
  cout << endl;
  cout << q.size() << endl;
  for (long long num : q) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
