#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  stack<long long int> s;
  s.push(1);
  long long int w = pow(2, 32), sum = 0;
  for (int i = 0; i < q; i++) {
    string t;
    cin >> t;
    if (t == "for") {
      long long int n;
      cin >> n;
      s.push(min(w, n * s.top()));
    } else if (t == "end")
      s.pop();
    else {
      sum += s.top();
    }
  }
  if (sum < w)
    cout << sum;
  else
    cout << "OVERFLOW!!!";
}
