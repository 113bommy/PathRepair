#include <bits/stdc++.h>
using namespace std;
const long long LINF = 1e18;
const int INF = 1e9;
const long double EPS = 1e-6;
const long long MOD = 1e9 + 7;
const string filename = "";
const bool testgen = false;
const bool testrun = true;
struct gen {
  void run() {
    for (int i = 0; i < 100; ++i) {
      cout << rand() << " " << rand() << " = " << endl;
    }
  }
};
struct prog {
  void run() {
    long long n;
    cin >> n;
    vector<pair<long long, long long>> vec(0);
    set<long long> used;
    long long last = 0;
    for (int i = 0; i < n; ++i) {
      long long a;
      cin >> a;
      if (used.find(a) == used.end())
        used.insert(a);
      else {
        vec.push_back(make_pair(last, i));
        last = i + 1;
        used.erase(used.begin(), used.end());
      }
    }
    if (vec.size() == 0)
      cout << -1;
    else {
      if (last != n) vec.rbegin()->second = n - 1;
      cout << vec.size() << endl;
      for (auto p : vec) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
      }
    }
  }
};
void run_file(const char *in, const char *out) {
  freopen(in, "r", stdin);
  freopen(out, "w", stdout);
  do {
    int cl = clock();
    prog p;
    p.run();
    fprintf(stderr, "Execution time: %Lf \n",
            (long double)(clock() - cl) / CLOCKS_PER_SEC * 1000);
    cout << endl;
    string s;
    cout.flush();
    do cin >> s;
    while (s != "=" && !cin.eof());
  } while (!cin.eof());
  fclose(stdout);
}
int main() {
  cin.sync_with_stdio(false);
  cout << fixed << setprecision(10);
  if (filename.compare("")) {
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
  }
  prog p;
  p.run();
  return 0;
}
