#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323;
long long int exp(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    res *= a;
    b--;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc, n, k;
  cin >> tc;
  for (int i = 0; i < tc; i += 1) {
    cin >> n >> k;
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    unordered_set<char> myset;
    for (char x : str) myset.insert(x);
    if (k == 1)
      cout << str << endl;
    else if (n == k)
      cout << str[0] << endl;
    else {
      if (myset.size() == 1) {
        int x = n / k;
        if (n % k != 0) x++;
        cout << str.substr(0, x) << endl;
      } else {
        bool ss = true;
        for (int i = 0; i < k - 1; i++) {
          if (str[i] != str[i + 1]) {
            ss = false;
            break;
          }
        }
        if (!ss)
          cout << str[k - 1] << endl;
        else if (ss && myset.size() == 2) {
          if (str[0] == str[k])
            cout << str.substr(k - 1, n - k + 1) << endl;
          else {
            int x = n / k;
            if (n % k == 0) x--;
            cout << str.substr(0, 1) + str.substr(k, x) << endl;
          }
        } else
          cout << str[0] + str.substr(k, n - k) << endl;
      }
    }
  }
}
