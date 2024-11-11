#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
const long long INFL = 1001001001001001001LL;
template <typename T>
void pv(T a, T b) {
  for (T i = a; i != b; ++i) cout << *i << " ";
  cout << endl;
}
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
int in() {
  int x;
  cin >> x;
  return x;
}
double fin() {
  double x;
  cin >> x;
  return x;
}
string sin() {
  string x;
  cin >> x;
  return x;
}
char chin() {
  char x;
  cin >> x;
  return x;
}
long long lin() {
  long long x;
  cin >> x;
  return x;
}
struct card {
  int a, b, c;
};
bool comp(card &a, card &b) { return a.a > b.a; }
int n, p, q, r;
long long sum[500001];
vector<pair<int, int> > bounds;
vector<card> cards;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(20);
  cin >> n >> p >> q >> r;
  cards.resize(n);
  for (int i = 0; i < (int)(n); ++i) {
    cin >> cards[i].a >> cards[i].b >> cards[i].c;
    bounds.push_back({cards[i].b, cards[i].c});
  }
  sort((cards).begin(), (cards).end(), comp);
  sort((bounds).rbegin(), (bounds).rend());
  int ind = -1;
  for (int i = 0; i < bounds.size(); i++) {
    if (ind == -1 || bounds[ind].second < bounds[i].second) {
      bounds[++ind] = bounds[i];
    }
  }
  bounds.resize(ind + 1);
  bounds.push_back({0, r});
  reverse((bounds).begin(), (bounds).end());
  bounds.push_back({q, 0});
  for (int i = 1; i < bounds.size(); i++) {
    sum[i] = sum[i - 1] + (long long)(bounds[i - 1].second - bounds[i].second) *
                              (q - bounds[i - 1].first);
  }
  int bb = p;
  int minb = 0, minc = 0;
  int pbnd = 0, pcnd = bounds.size() - 1;
  long long sol = 0;
  cards.push_back({0, 0, 0});
  for (int i = 0; i <= n; i++) {
    if (bb > cards[i].a) {
      while (pbnd < bounds.size() && bounds[pbnd].first < minb) pbnd++;
      while (pcnd > 0 && bounds[pcnd].second < minc) pcnd--;
      if (pbnd > pcnd) {
        sol += (long long)(bb - cards[i].a) * (q - minb) * (r - minc);
      } else {
        sol += (long long)(bb - cards[i].a) *
               (sum[pcnd] - sum[pbnd] +
                (long long)(bounds[pcnd].second - minc) *
                    (q - bounds[pcnd].first) +
                (long long)(q - minb) * (r - bounds[pbnd].second));
      }
      bb = cards[i].a;
    }
    uax(minb, cards[i].b);
    uax(minc, cards[i].c);
  }
  cout << sol << endl;
  return 0;
}
