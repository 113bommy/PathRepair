#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100500;
char buf[10];
string scan_token() {
  scanf("%s", buf);
  return buf;
}
int n;
string name[N];
bool sample[N];
int samples_cnt;
string temp_file;
set<string> all_names;
vector<pair<string, string>> ops;
vector<string> sample_holes, test_holes;
vector<int> sample_bad, test_bad;
bool try_parse(const string& s, int& num) {
  if (s.empty() || s[0] == '0') return false;
  for (char c : s)
    if (!isdigit(c)) return false;
  num = atoi(s.c_str());
  return true;
}
void fill_bad() {
  sample_bad.clear();
  test_bad.clear();
  for (int i = 0; i < n; i++) {
    int num;
    if (!try_parse(name[i], num)) continue;
    if (1 <= num && num <= samples_cnt && !sample[i]) test_bad.push_back(i);
    if (samples_cnt < num && num <= n && sample[i]) sample_bad.push_back(i);
  }
}
bool generate_temp(int p) {
  if (p == 6) return !all_names.count(temp_file);
  for (char c = 'a'; c <= 'z'; c++) {
    temp_file += c;
    if (generate_temp(p + 1)) return true;
    temp_file.pop_back();
  }
  return false;
}
void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    name[i] = scan_token();
    all_names.insert(name[i]);
    int t;
    scanf("%d", &t);
    sample[i] = t == 1;
    samples_cnt += t;
  }
  generate_temp(0);
  for (int i = 1; i <= n; i++) {
    string f = to_string(i);
    if (all_names.count(f)) continue;
    if (i <= samples_cnt)
      sample_holes.push_back(f);
    else
      test_holes.push_back(f);
  }
  fill_bad();
  bool any = true;
  while (any) {
    any = false;
    if (!test_bad.empty() && !test_holes.empty()) {
      int i = test_bad.back();
      test_bad.pop_back();
      string hole = test_holes.back();
      test_holes.pop_back();
      sample_holes.push_back(name[i]);
      ops.emplace_back(name[i], hole);
      name[i] = hole;
      any = true;
    }
    if (!sample_bad.empty() && !sample_holes.empty()) {
      int i = sample_bad.back();
      sample_bad.pop_back();
      string hole = sample_holes.back();
      sample_holes.pop_back();
      test_holes.push_back(name[i]);
      ops.emplace_back(name[i], hole);
      name[i] = hole;
      any = true;
    }
  }
  for (int i = 0; i < n; i++) {
    int num;
    if (try_parse(name[i], num) && 1 <= num && num <= n) continue;
    if (sample[i]) {
      if (!sample_holes.empty()) {
        string hole = sample_holes.back();
        sample_holes.pop_back();
        ops.emplace_back(name[i], hole);
        name[i] = hole;
      }
    } else {
      if (!test_holes.empty()) {
        string hole = test_holes.back();
        test_holes.pop_back();
        ops.emplace_back(name[i], hole);
        name[i] = hole;
      }
    }
  }
  fill_bad();
  if (sample_bad.size() != test_bad.size()) throw logic_error("baaad");
  if (!sample_bad.empty()) {
    ops.emplace_back(name[sample_bad[0]], temp_file);
    for (int i = 0; i < (int)sample_bad.size(); i++) {
      ops.emplace_back(name[test_bad[i]], name[sample_bad[i]]);
      if (i + 1 < (int)sample_bad.size())
        ops.emplace_back(name[sample_bad[i + 1]], name[test_bad[i]]);
    }
    ops.emplace_back(temp_file, name[test_bad.back()]);
  }
  printf("%d\n", (int)ops.size());
  for (const auto& e : ops)
    printf("move %s %s\n", e.first.c_str(), e.second.c_str());
}
int main() {
  solve();
  (void)0;
}
