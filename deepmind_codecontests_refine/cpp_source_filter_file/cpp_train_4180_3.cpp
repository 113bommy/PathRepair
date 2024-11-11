#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
int main() {
  time_point<steady_clock> start = steady_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  string t;
  cin >> t;
  int n = t.length();
  string t1(n, 'a');
  string t2(n, 'a');
  string t3(n, 'a');
  for (int i = 0; i < n; i++) {
    t1[i] += i / 26 / 26;
    t2[i] += i / 26;
    t3[i] += i % 26;
  }
  cout << "? " << t1 << endl;
  cin >> t1;
  cout << "? " << t2 << endl;
  cin >> t2;
  cout << "? " << t3 << endl;
  cin >> t3;
  vector<int> p(n);
  for (int i = 0; i < n; i++)
    p[i] = (t1[i] - 'a') * 26 * 26 + (t2[i] - 'a') * 26 + t3[i] - 'a';
  string s(n, 'a');
  for (int i = 0; i < n; i++) s[p[i]] = t[i];
  cout << "! " << s << endl;
  cerr << endl
       << "------------------------------" << endl
       << "Time: "
       << duration<double, milli>(steady_clock::now() - start).count() << " ms."
       << endl;
  return 0;
}
