#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long INFL = LLONG_MAX;
const long double pi = acos(-1);
int N, K;
string result;
int cnt;
int ask(int a, int b, int c) {
  cnt++;
  if (cnt > 60 * N) {
    cout << "TOO MANY QUESTIONS" << '\n';
  }
  cout << "? " << a << " " << b << " " << c << '\n';
  cout.flush();
  cin >> result;
  return result == "YES";
}
void answer(int u) {
  cout << "! " << u << '\n';
  exit(0);
}
int main() {
  mt19937 rng(505);
  cin >> N >> K;
  vector<pair<int, int> > results;
  int random_query_count = 30;
  string result;
  for (int u = 1; u <= N; u++) {
    int success = 0;
    for (int i = 1; i <= random_query_count; i++) {
      int a = rng() % N + 1;
      int b = rng() % N + 1;
      if (ask(a, u, b)) {
        success++;
      }
    }
    results.push_back(make_pair(success, u));
  }
  sort(results.begin(), results.end());
  int expected = (N - 1) / K;
  reverse(results.begin(), results.end());
  for (int i = 0; i < min(60 - random_query_count, int((results).size()));
       i++) {
    int u = results[i].second;
    int another = 1;
    if (u == another) another = 2;
    int success = 0;
    for (int v = 1; v <= N; v++) {
      if (ask(another, u, v)) {
        success++;
      }
    }
    if (N - success == expected) {
      answer(u);
    }
  }
}
