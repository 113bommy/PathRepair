#include <bits/stdc++.h>
const long long MODULE = 1000000007l;
using namespace std;
mt19937_64 RANDOM(chrono::steady_clock::now().time_since_epoch().count());
uniform_real_distribution<long double> RANDOM_DISTRIBUTION(0.0, 1.0);
inline long double RANDOM_FLOAT() { return RANDOM_DISTRIBUTION(RANDOM); }
inline bool ends_with(std::string const& value, std::string const& ending) {
  if (ending.size() > value.size()) return false;
  return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}
inline bool starts_with(std::string const& value, std::string const& begining) {
  return value.rfind(begining) == 0;
}
inline vector<string> split(const std::string& value, char delim) {
  vector<string> result;
  string currVal;
  for (long long i = 0; i < value.size(); ++i) {
    if (value[i] == delim) {
      if (!currVal.empty()) {
        result.push_back(currVal);
        currVal.clear();
      }
    } else {
      currVal += value[i];
    }
  }
  if (!currVal.empty()) {
    result.push_back(currVal);
    currVal.clear();
  }
  return result;
}
inline string join(const vector<string>& values, char delim) {
  if (values.empty()) {
    return string();
  }
  string result = values[0];
  for (long long i = 1; i < values.size(); ++i) {
    result += delim;
    result += values[i];
  }
  return result;
}
class CMaskaPodseti {
 public:
  long long ipToNum(const string& val) {
    auto vals = split(val, '.');
    long long res = 0;
    for (long long i = 0; i < 4; ++i) {
      long long shift = (4 - i - 1) * 8;
      res += stoi(vals[i]) << shift;
    }
    return res;
  }
  string numToIp(long long val) {
    long long mask = 255;
    vector<string> vals;
    for (long long i = 0; i < 4; ++i) {
      long long shift = (4 - i - 1) * 8;
      long long curr = (val >> shift) & mask;
      vals.push_back(to_string(curr));
    }
    return join(vals, '.');
  }
  void dosolve(std::istream& in, std::ostream& out) {
    long long n, m;
    in >> n >> m;
    vector<long long> a;
    for (long long i = 0; i < n; i++) {
      string v;
      in >> v;
      a.push_back(ipToNum(v));
    }
    long long currMask = 0;
    for (long long i = 0; i <= 30; ++i) {
      long long currBit = 1ll << (31ll - i);
      currMask |= currBit;
      set<long long> nets;
      for (auto addr : a) {
        long long net = addr & currMask;
        nets.insert(net);
      }
      if (nets.size() == m) {
        out << numToIp(currMask) << endl;
        return;
      }
    }
    out << -1 << endl;
  }
  void solve(std::istream& in, std::ostream& out) {
    int n = 1;
    for (unsigned long long i = 0; i < n; ++i) {
      dosolve(in, out);
    }
  }
};
int main() {
  std::cin.tie(0);
  std::cout.tie(0);
  std::cout << setprecision(numeric_limits<long double>::digits10 + 1);
  CMaskaPodseti solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
