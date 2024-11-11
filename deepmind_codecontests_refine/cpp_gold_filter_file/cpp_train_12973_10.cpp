#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using LD = long double;
using pii = pair<int, int>;
using veci = vector<int>;
using vecii = vector<veci>;
const LD eps = 1e-9;
const LD pi = acos(-1.0);
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;
struct problem_t {
  void solve(istream& cin, ostream& cout) {
    LL n;
    cin >> n;
    do {
      if (cin.fail()) {
        throw std::runtime_error("end of input");
      }
    } while (0);
    LL res = n * 2 + 2;
    LL i = 0;
    while (i * i <= n) {
      ++i;
    }
    --i;
    res = 4 * i;
    n -= i * i;
    ;
    ;
    if (n > 0 && n <= i) {
      res += 2;
    } else if (n > i) {
      res += 4;
    }
    cout << res << endl;
  }
};
struct brute_t {
  void solve(istream& cin, ostream& cout) {
    do {
      if (cin.fail()) {
        throw std::runtime_error("end of input");
      }
    } while (0);
  }
};
template <typename Solution>
struct solution_str {
  string solve(string input) {
    istringstream is(input);
    ostringstream os;
    Solution().solve(is, os);
    return os.str();
  }
};
std::string gen_input(int it) {
  (void)it;
  return "";
}
void stress() {
  for (int it = 0; it < 1000; ++it) {
    auto input = gen_input(it);
    auto brute_out = solution_str<brute_t>().solve(input);
    auto sol_out = solution_str<problem_t>().solve(input);
    if (sol_out != brute_out) {
      cerr << "WA #" << it << endl;
      cerr << "input: " << endl;
      cerr << input << endl;
      cerr << "expected: " << brute_out << endl;
      cerr << "got: " << sol_out << endl;
      exit(1);
    }
  }
  cerr << "OK" << endl;
}
int main(int argc, char* argv[]) {
  (void)argc;
  (void)argv;
  ios::sync_with_stdio(false);
  cin.tie(0);
  if (argc > 1) {
    stress();
    exit(0);
  }
  clock_t tstart = clock();
  do {
    try {
      problem_t p;
      p.solve(cin, cout);
    } catch (const std::exception& e) {
      break;
    }
  } while (true);
  clock_t tend = clock();
  return 0;
}
