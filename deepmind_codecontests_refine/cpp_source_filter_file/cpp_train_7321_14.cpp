#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const double pi = 3.14159265358979323846264338327950288419716939937511;
const double eps = 1e-13;
char ch_ch_ch[1 << 20];
string gs() {
  scanf("%s", ch_ch_ch);
  return string(ch_ch_ch);
}
string gl() {
  gets(ch_ch_ch);
  return string(ch_ch_ch);
}
vector<pair<pair<int, int>, int> > buy;
vector<pair<pair<int, int>, int> > shoe;
int n, m;
long long dp[100100][2][2];
void conv(int b, int fb, int sb, int &nfb, int &nsb) {
  nfb = nsb = 0;
  if (b + 1 < buy.size()) {
    if (buy[b + 1].first.first == buy[b].first.first)
      nfb = fb, nsb = sb;
    else if (buy[b + 1].first.first == buy[b].first.first + 1)
      nfb = sb, nsb = 0;
  }
}
long long R(int b, int fb, int sb) {
  if (b == buy.size()) return 0;
  long long &r = dp[b][fb][sb];
  if (r != -1) return r;
  int fs = buy[b].first.first;
  int ss = fs + 1;
  int nfb, nsb;
  conv(b, fb, sb, nfb, nsb);
  r = R(b + 1, nfb, nsb);
  int ind =
      lower_bound(shoe.begin(), shoe.end(), make_pair(make_pair(fs, 0), 0)) -
      shoe.begin();
  if (!fb && ind < shoe.size() && shoe[ind].first.first == fs &&
      shoe[ind].first.second <= buy[b].first.second) {
    conv(b, 1, sb, nfb, nsb);
    r = max(r, shoe[ind].first.second + R(b + 1, nfb, nsb));
  }
  ind = lower_bound(shoe.begin(), shoe.end(), make_pair(make_pair(ss, 0), 0)) -
        shoe.begin();
  if (!sb && ind < shoe.size() && shoe[ind].first.first == ss &&
      shoe[ind].first.second <= buy[b].first.second) {
    conv(b, fb, 1, nfb, nsb);
    r = max(r, shoe[ind].first.second + R(b + 1, nfb, nsb));
  }
  return r;
}
vector<pair<int, int> > res;
void Rec(int b, int fb, int sb) {
  if (b == buy.size()) return;
  int fs = buy[b].first.first;
  int ss = fs + 1;
  int nfb, nsb;
  conv(b, fb, sb, nfb, nsb);
  long long r = R(b + 1, nfb, nsb);
  int sh = -1;
  int ind =
      lower_bound(shoe.begin(), shoe.end(), make_pair(make_pair(fs, 0), 0)) -
      shoe.begin();
  if (!fb && ind < shoe.size() && shoe[ind].first.first == fs &&
      shoe[ind].first.second <= buy[b].first.second) {
    conv(b, 1, sb, nfb, nsb);
    long long cur = shoe[ind].first.second + R(b + 1, nfb, nsb);
    if (cur > r) {
      cur = r;
      sh = 1;
    }
  }
  ind = lower_bound(shoe.begin(), shoe.end(), make_pair(make_pair(ss, 0), 0)) -
        shoe.begin();
  if (!sb && ind < shoe.size() && shoe[ind].first.first == ss &&
      shoe[ind].first.second <= buy[b].first.second) {
    conv(b, fb, 1, nfb, nsb);
    long long cur = shoe[ind].first.second + R(b + 1, nfb, nsb);
    if (cur > r) {
      cur = r;
      sh = 2;
    }
  }
  if (sh == -1) {
    conv(b, fb, sb, nfb, nsb);
    Rec(b + 1, nfb, nsb);
  } else if (sh == 1) {
    conv(b, 1, sb, nfb, nsb);
    Rec(b + 1, nfb, nsb);
    ind =
        lower_bound(shoe.begin(), shoe.end(), make_pair(make_pair(fs, 0), 0)) -
        shoe.begin();
    res.push_back(make_pair(buy[b].second, shoe[ind].second));
  } else {
    conv(b, fb, 1, nfb, nsb);
    Rec(b + 1, nfb, nsb);
    ind =
        lower_bound(shoe.begin(), shoe.end(), make_pair(make_pair(ss, 0), 0)) -
        shoe.begin();
    res.push_back(make_pair(buy[b].second, shoe[ind].second));
  }
}
void solution() {
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i) {
    int c, s;
    scanf("%d%d", &c, &s);
    shoe.push_back(make_pair(make_pair(s, c), i + 1));
  }
  scanf("%d", &m);
  for (int i = 0; i < (m); ++i) {
    int c, s;
    scanf("%d%d", &c, &s);
    buy.push_back(make_pair(make_pair(s, c), i + 1));
  }
  sort(buy.begin(), buy.end());
  sort(shoe.begin(), shoe.end());
  memset(dp, -1, sizeof(dp));
  cout << R(0, 0, 0) << endl;
  Rec(0, 0, 0);
  printf("%d\n", res.size());
  for (int i = 0; i < (res.size()); ++i)
    printf("%d %d\n", res[i].first, res[i].second);
}
int main(int argc, char **argv) {
  solution();
  return 0;
}
