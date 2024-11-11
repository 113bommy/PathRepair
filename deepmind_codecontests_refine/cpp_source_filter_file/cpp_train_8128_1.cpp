#include <bits/stdc++.h>
using namespace std;
const bool online_judge = true;
const long long inf = 1LL << 60;
long long toInt(string s) {
  long long res;
  stringstream ss;
  ss << s;
  ss >> res;
  return res;
}
string toString(long long n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
void run() {
  string s;
  long long k;
  cin >> s >> k;
  map<char, long long> cnt;
  for (long long i = 0; i < ((long long)((s).size())); i++) {
    cnt[s[i]]++;
  }
  vector<tuple<long long, char>> v;
  for (auto it = cnt.begin(); it != cnt.end(); ++it) {
    v.emplace_back(it->second, it->first);
  }
  sort((v).begin(), (v).end());
  long long index = 0;
  while (true) {
    if (index >= (long long)v.size() || get<0>(v[index]) > k) break;
    k -= get<0>(v[index++]);
  }
  long long last[30];
  memset(last, 0, sizeof(last));
  for (long long i = index; i < ((long long)((v).size())); i++) {
    last[get<1>(v[index]) - 'a'] = 1;
  }
  long long a = 0;
  for (long long i = 0; i < 30; i++)
    if (last[i]) a++;
  cout << a << endl;
  string ans = "";
  for (long long i = 0; i < ((long long)((s).size())); i++) {
    if (last[s[i] - 'a']) ans.push_back(s[i]);
  }
  cout << ans << endl;
}
int main(int argc, char *argv[]) {
  run();
  return 0;
}
