#include <bits/stdc++.h>
const double PI =
    3.14159265358979323846264338327950288419716939937510582097494459230;
using namespace std;
int return_() { return 0; }
long long int prime(long long int n) {
  if (n % 2 == 0 && n != 2 || n < 2)
    return false;
  else {
    for (long long int i = 3; i * i <= n; i += 2) {
      if (n % i == 0) {
        return false;
      }
    }
  }
  return true;
}
long long int gcd(long long int n, long long int m) {
  if (n % m == 0)
    return m;
  else
    return gcd(m, n % m);
}
long long int lcm(long long int n, long long int m) {
  return n * m / gcd(n, m);
}
long long int fact(long long int n) {
  if (n == 1)
    return 1;
  else
    return n * fact(n - 1);
}
int sumdigit(int n) {
  int sum = 0;
  while (n) {
    sum += (n % 10);
    n /= 10;
  }
  return sum;
}
string tobinary(long long int n) {
  string s;
  while (n) {
    s += (n % 2) + '0';
    n /= 2;
  }
  reverse((s).begin(), (s).end());
  return s;
}
string tostring(double n) {
  double m = n;
  string x;
  stringstream ss;
  ss << m;
  ss >> x;
  return x;
}
char tochar(int n) {
  int m = n;
  char x;
  stringstream ss;
  ss << m;
  ss >> x;
  return x;
}
float log2(int n) { return log10(n) / log10(2); }
const long long int MOD = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, p;
  double k;
  string s;
  cin >> n >> m >> k;
  vector<pair<string, int> > vp, vp2;
  bool f[105] = {0};
  pair<string, int> pr;
  for (int i = 0; i < n; i++) {
    cin >> s >> p;
    vp.push_back(pair<string, float>(s, (p * k)));
  }
  for (int i = 0; i < m; i++) {
    cin >> s;
    for (int j = 0; j < vp.size(); j++) {
      if (s == vp[j].first) {
        if (vp[j].second < 100) vp[j].second = 0;
        vp2.push_back(pair<string, int>(s, vp[j].second));
        f[j] = 1;
        break;
      } else if (j == vp.size() - 1) {
        vp2.push_back(pair<string, int>(s, 0));
      }
    }
  }
  for (int i = 0; i < vp.size(); i++) {
    if (!f[i]) {
      if (vp[i].second >= 100)
        vp2.push_back(pair<string, int>(vp[i].first, vp[i].second));
    }
  }
  for (int i = 0; i < vp2.size(); i++) {
    for (int j = i + 1; j < vp2.size(); j++) {
      if (lexicographical_compare(vp2[j].first.begin(), vp2[j].first.end(),
                                  vp2[i].first.begin(), vp2[i].first.end())) {
        pair<string, float> pr;
        pr.first = vp2[i].first, pr.second = vp2[i].second;
        vp2[i].first = vp2[j].first, vp2[i].second = vp2[j].second;
        vp2[j].first = pr.first, vp2[j].second = pr.second;
      }
    }
  }
  cout << vp2.size();
  cout << "\n";
  for (int i = 0; i < vp2.size(); i++) {
    cout << vp2[i].first << " " << vp2[i].second;
    cout << "\n";
  }
  return 0;
}
