#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (auto i = 0; i < n; i += 1) {
      cin >> a[i];
    }
    vector<long long> v;
    long long c = 1;
    long long eq = a[0];
    for (auto i = 1; i < n; i += 1) {
      if (a[i] == eq)
        c++;
      else {
        v.push_back(c);
        c = 1;
        eq = a[i];
      }
    }
    v.push_back(c);
    if (v.size() < 3)
      cout << "0 0 0\n";
    else {
      long long i = 0;
      long long sum = 0;
      while (i < v.size() and (sum + v[i]) <= n / 2) {
        sum += v[i];
        i++;
      }
      long long g = v[0];
      long long s = 0;
      long long j = 1;
      while (s <= g and j < i) {
        s += v[j];
        j++;
      }
      long long b = 0;
      while (j < i) {
        b += v[j];
        j++;
      }
      if (g >= s or g >= b or ((g + s + b) > n / 2) or g == 0 or s == 0 or
          b == 0)
        cout << "0 0 0\n";
      else
        cout << g << " " << b << " " << s << "\n";
    }
  }
  return 0;
}
