#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  if (k > 50)
    cout << "No";
  else {
    set<int> s;
    for (int i = 1; i < k + 1; i++) {
      s.insert(n % i);
    }
    if (s.size() == k)
      cout << "Yes";
    else
      cout << "No";
  }
}
