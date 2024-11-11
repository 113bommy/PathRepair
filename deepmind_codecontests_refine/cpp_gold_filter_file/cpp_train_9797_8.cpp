#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, k;
  cin >> n >> k;
  long long int x = (2 * k + 1);
  vector<long long int> v;
  if (n <= (k + 1)) {
    cout << 1 << endl;
    cout << 1;
  } else {
    v.push_back(k + 1);
    for (long long int i = (k + 2 + 2 * k); i <= n; i += (2 * k + 1))
      v.push_back(i);
    long long int flag = true;
    long long int s_fact = 0;
    if (n - v[v.size() - 1] >= (k + 1)) {
      v.push_back(n);
      s_fact = v[v.size() - 2] + k - v[v.size() - 1] + k + 1;
      flag = false;
    }
    cout << v.size() << endl;
    for (long long int i = 0; i < v.size() - 1; i++) {
      if (flag == false)
        cout << v[i] - s_fact << " ";
      else
        cout << v[i] << " ";
    }
    cout << v[v.size() - 1];
  }
}
