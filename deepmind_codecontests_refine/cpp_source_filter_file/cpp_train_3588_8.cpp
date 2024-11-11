#include <bits/stdc++.h>
using namespace std;
const int inf = 2e8 + 5;
const long long l_inf = 9e18 + 5;
template <typename T>
inline T mod(T a, T b) {
  return (a % b + b) % b;
}
template <typename T, typename T2>
ostream &operator<<(ostream &s, const pair<T, T2> &p) {
  return s << p.first << ' ' << p.second << ' ';
}
template <typename T, typename T2>
istream &operator>>(istream &s, pair<T, T2> &p) {
  return s >> p.first >> p.second;
}
template <typename T>
ostream &operator<<(ostream &s, const vector<T> &v) {
  for (auto it : v) s << it << ' ';
  return s;
}
template <typename T>
istream &operator>>(istream &s, vector<T> &v) {
  for (auto it = (v).begin(), it_ = (v).end(); it != it_; it++) s >> *it;
  return s;
}
template <typename T>
void read_range(T beg, T end) {
  while (beg != end) cin >> *beg++;
}
template <typename T>
void print_range(T beg, T end) {
  while (beg != end) cout << *beg++ << ' ';
}
struct reader {
  template <typename T>
  reader &operator,(T &v) {
    cin >> v;
    return *this;
  }
} rdr;
struct debugger {
  template <typename T>
  debugger &operator,(const T &v) {
    cerr << v << ", ";
    return *this;
  }
} dbg;
inline int team_no(char c) {
  if (c == 'h') return 0;
  return 1;
}
inline int card_no(char c) {
  if (c == 'y') return 0;
  return 1;
}
string team_name[2];
struct Foul {
  int time;
  char team_no;
  int player_no;
  char card_no;
};
bool operator<(const Foul &f1, const Foul &f2) { return f1.time < f2.time; }
istream &operator>>(istream &is, Foul &f) {
  is >> f.time >> f.team_no >> f.player_no >> f.card_no;
  f.team_no = team_no(f.team_no);
  f.card_no = card_no(f.card_no);
  return is;
}
ostream &operator<<(ostream &os, const Foul &f) {
  return os << team_name[f.team_no] << ' ' << f.player_no << ' ' << f.time
            << '\n';
}
Foul fouls[100];
int yellow_cnt[2][100];
bool given[2][100];
int main() {
  ios_base::sync_with_stdio(false);
  read_range(team_name, team_name + 2);
  int n;
  rdr, n;
  ;
  read_range(fouls, fouls + n);
  sort(fouls, fouls + n);
  for (int i = 0, end = (n); i < end; i++)
    if (not given[fouls[i].team_no][fouls[i].player_no] and
            fouls[i].card_no == 1 or
        yellow_cnt[fouls[i].team_no][fouls[i].player_no] == 1) {
      given[fouls[i].team_no][fouls[i].player_no] = true;
      cout << fouls[i];
    } else
      yellow_cnt[fouls[i].team_no][fouls[i].player_no]++;
  return 0;
}
