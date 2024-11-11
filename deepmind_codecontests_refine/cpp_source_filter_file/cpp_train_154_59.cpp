#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-9;
const long long int mod = 1e9 + 7;
const long long int inf = 1LL << 30;
const int MAXN = 1e5 + 5;
void cp() {
  double x, y, z;
  cin >> x >> y >> z;
  vector<double> arr;
  if (x > 1. || y > 1. || z > 1.) {
    arr.push_back(z * log(y) + log(log(x)));
    arr.push_back(y * log(z) + log(log(x)));
    arr.push_back(log(y) + log(z) + log(log(x)));
    arr.push_back(log(y) + log(z) + log(log(x)));
    swap(x, y);
    arr.push_back(z * log(y) + log(log(x)));
    arr.push_back(y * log(z) + log(log(x)));
    arr.push_back(log(y) + log(z) + log(log(x)));
    arr.push_back(log(y) + log(z) + log(log(x)));
    swap(x, z);
    arr.push_back(z * log(y) + log(log(x)));
    arr.push_back(y * log(z) + log(log(x)));
    arr.push_back(log(y) + log(z) + log(log(x)));
    arr.push_back(log(y) + log(z) + log(log(x)));
    for (double &X : arr)
      if (isnan(X)) X = 0;
  } else {
    arr.push_back(pow(x, pow(y, z)));
    arr.push_back(pow(x, pow(z, y)));
    arr.push_back(pow(x, y * z));
    arr.push_back(pow(x, y * z));
    swap(x, y);
    arr.push_back(pow(x, pow(y, z)));
    arr.push_back(pow(x, pow(z, y)));
    arr.push_back(pow(x, y * z));
    arr.push_back(pow(x, y * z));
    swap(x, z);
    arr.push_back(pow(x, pow(y, z)));
    arr.push_back(pow(x, pow(z, y)));
    arr.push_back(pow(x, y * z));
    arr.push_back(pow(x, y * z));
  }
  string ans;
  int idx = max_element(arr.begin(), arr.end()) - begin(arr);
  if (idx == 0)
    ans = "x^y^z";
  else if (idx == 1)
    ans = "x^z^y";
  else if (idx == 2)
    ans = "(x^y)^z";
  else if (idx == 3)
    ans = "(x^z)^y";
  else if (idx == 4)
    ans = "y^x^z";
  else if (idx == 5)
    ans = "y^z^x";
  else if (idx == 6)
    ans = "(y^x)^z";
  else if (idx == 7)
    ans = "(y^z)^x";
  else if (idx == 8)
    ans = "z^x^y";
  else if (idx == 9)
    ans = "z^y^x";
  else if (idx == 10)
    ans = "(z^x)^y";
  else
    ans = "(z^y)^x";
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  t = 1;
  while (t--) {
    cp();
  }
  return 0;
}
