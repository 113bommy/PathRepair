#include <bits/stdc++.h>
using namespace std;
string DBG_DLM(int& i) { return (i++ == 0 ? "" : ", "); }
template <class T>
ostream& operator<<(ostream& os, vector<T> v);
template <class T>
ostream& operator<<(ostream& os, set<T> v);
template <class T>
ostream& operator<<(ostream& os, queue<T> q);
template <class T>
ostream& operator<<(ostream& os, priority_queue<T> q);
template <class T, class K>
ostream& operator<<(ostream& os, pair<T, K> p);
template <class T, class K>
ostream& operator<<(ostream& os, map<T, K> mp);
template <class T, class K>
ostream& operator<<(ostream& os, unordered_map<T, K> mp);
template <int I, class TPL>
void DBG(ostream& os, TPL t) {}
template <int I, class TPL, class H, class... Ts>
void DBG(ostream& os, TPL t) {
  os << (I == 0 ? "" : ", ") << get<I>(t);
  DBG<I + 1, TPL, Ts...>(os, t);
}
template <class T, class K>
void DBG(ostream& os, pair<T, K> p, string delim) {
  os << "(" << p.first << delim << p.second << ")";
}
template <class... Ts>
ostream& operator<<(ostream& os, tuple<Ts...> t) {
  os << "(";
  DBG<0, tuple<Ts...>, Ts...>(os, t);
  os << ")";
  return os;
}
template <class T, class K>
ostream& operator<<(ostream& os, pair<T, K> p) {
  DBG(os, p, ", ");
  return os;
}
template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
  {
    int i = 0;
    os << "{";
    {
      for (auto&& t : v) {
        os << DBG_DLM(i) << t;
      };
    }
    os << "}";
    return os;
  };
}
template <class T>
ostream& operator<<(ostream& os, set<T> s) {
  {
    int i = 0;
    os << "{";
    {
      for (auto&& t : s) {
        os << DBG_DLM(i) << t;
      };
    }
    os << "}";
    return os;
  };
}
template <class T>
ostream& operator<<(ostream& os, queue<T> q) {
  {
    int i = 0;
    os << "{";
    {
      for (; q.size(); q.pop()) {
        os << DBG_DLM(i) << q.front();
      };
    }
    os << "}";
    return os;
  };
}
template <class T>
ostream& operator<<(ostream& os, priority_queue<T> q) {
  {
    int i = 0;
    os << "{";
    {
      for (; q.size(); q.pop()) {
        os << DBG_DLM(i) << q.top();
      };
    }
    os << "}";
    return os;
  };
}
template <class T, class K>
ostream& operator<<(ostream& os, map<T, K> m) {
  {
    int i = 0;
    os << "{";
    {
      for (auto&& p : m) {
        os << DBG_DLM(i);
        DBG(os, p, "->");
      };
    }
    os << "}";
    return os;
  };
}
template <class T, class K>
ostream& operator<<(ostream& os, unordered_map<T, K> m) {
  {
    int i = 0;
    os << "{";
    {
      for (auto&& p : m) {
        os << DBG_DLM(i);
        DBG(os, p, "->");
      };
    }
    os << "}";
    return os;
  };
}
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using vs = vector<string>;
using vvs = vector<vs>;
using vvvs = vector<vvs>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vvvpii = vector<vvpii>;
template <class A, class B>
bool amax(A& a, const B& b) {
  return b > a ? a = b, 1 : 0;
}
template <class A, class B>
bool amin(A& a, const B& b) {
  return b < a ? a = b, 1 : 0;
}
ll ri() {
  ll l;
  cin >> l;
  return l;
}
string rs() {
  string s;
  cin >> s;
  return s;
}
using Event = pair<int, pii>;
int calc_safe_time(int hp, int reg, int damage) { return (damage - hp) / reg; }
ll solve() {
  int n = ri(), m = ri();
  ll bounty = ri(), increase = ri(), damage = ri();
  int mh_le_damage = 0;
  priority_queue<Event, vector<Event>, greater<Event>> q;
  int count = 0;
  vl M(n), H(n), R(n);
  for (int i = int(0); i < int(n); ++i) {
    M[i] = ri();
    H[i] = ri();
    R[i] = ri();
    if (M[i] <= damage) {
      mh_le_damage++;
    } else if (H[i] <= damage) {
      count++;
      if (R[i] > 0) {
        int need_time = calc_safe_time(H[i], R[i], damage);
        q.emplace(need_time, make_pair(-1, i));
        q.emplace(need_time + 1, make_pair(-1, i));
      }
    }
  }
  if (mh_le_damage && increase) return -1;
  vi ET(m), EE(m), EH(m);
  for (int i = int(0); i < int(m); ++i) {
    ET[i] = ri();
    EE[i] = ri() - 1;
    EH[i] = ri();
    int reg = R[EE[i]];
    int mh = M[EE[i]];
    if (mh <= damage) continue;
    q.emplace(ET[i] - 1, make_pair(-1, EE[i]));
    q.emplace(ET[i], make_pair(EH[i], EE[i]));
    if (EH[i] <= damage) {
      if (reg > 0) {
        int need_time = calc_safe_time(EH[i], reg, damage);
        q.emplace(ET[i] + need_time, make_pair(-1, EE[i]));
        q.emplace(ET[i] + need_time + 1, make_pair(-1, EE[i]));
      }
    }
  }
  ll ans = (mh_le_damage + count) * (bounty + increase * 0);
  vi L(n);
  while (((int)(q).size())) {
    int tim = q.top().first;
    int toh = q.top().second.first;
    int ene = q.top().second.second;
    q.pop();
    ;
    ll cur = H[ene];
    ll nex;
    if (toh == -1) {
      int las = L[ene];
      ll spe = tim - las;
      nex = min(M[ene], cur + spe * R[ene]);
    } else {
      nex = toh;
    }
    if (cur <= damage && nex > damage) count--;
    if (cur > damage && nex <= damage) count++;
    H[ene] = nex;
    L[ene] = tim;
    if (((int)(q).size()) == 0 || q.top().first > tim) {
      ll cc = count + mh_le_damage;
      ll cand = cc * (bounty + tim * increase);
      ;
      amax(ans, cand);
      ;
    }
  }
  if (increase) {
    for (int i = int(0); i < int(m); ++i) {
      if (R[i] == 0 && H[i] <= damage) return -1;
    }
  }
  return ans;
}
void Main() { cout << solve() << endl; }
signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  Main();
  return 0;
}
