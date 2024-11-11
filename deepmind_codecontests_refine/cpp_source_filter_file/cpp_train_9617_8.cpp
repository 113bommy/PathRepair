#include <bits/stdc++.h>
using namespace std;
int main() {
  deque<long long int> myints(1, 0);
  long long int n = 0, t = 0, a = 0, x = 0, l = 0;
  long double sum = 0, div = 0;
  cin >> n;
  deque<long long int> arr(200005, 0);
  for (unsigned int i = 0; i < n; i++) {
    cin >> t;
    if (t == 1) {
      cin >> a >> x;
      arr[a] += x;
      sum += a * x;
    } else if (t == 2) {
      cin >> l;
      myints.push_back(l);
      sum += l;
    } else if (t == 3 && myints.size() >= 2) {
      arr[myints.size() - 2] += arr[myints.size() - 1];
      sum -= myints[myints.size() - 1];
      sum -= arr[myints.size() - 1];
      arr[myints.size() - 1] = 0;
      myints.pop_back();
    }
    div = sum / myints.size();
    cout.precision(6);
    cout.setf(ios::fixed | ios::showpoint);
    cout << div << endl;
  }
  return 0;
}
