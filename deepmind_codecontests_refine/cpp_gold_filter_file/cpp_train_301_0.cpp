#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
#include<deque>
#include<algorithm>
#include<map>
#include<set>
#include<cstdlib>
#include<climits>
#include<cassert>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;

const ll LLINF = LLONG_MAX;
const bool debug = false;
const string opr = "01+-*=()";

string context;
int n;

ll parse_E(int&,string&);

ll parse_F(int &p,string &s) {
  if( p >= (int)s.size() ) return LLINF;
  if( s[p] == '+' ) return LLINF;
  if( s[p] == '-' ) {
    ++p;
    ll v = parse_F(p,s);
    if( v == LLINF ) return LLINF;
    return v * -1LL;
  } 
  if( s[p] == '(' ) {
    ++p;
    ll v = parse_E(p,s);
    if( v == LLINF ) return LLINF;
    if( p >= (int)s.size() ) return LLINF;
    if( s[p] != ')' ) return LLINF;
    ++p;
    if( p < (int)s.size() && ( s[p] == '0' || s[p] == '1' ) ) return LLINF;
    return v;
  }
  int cnt = 0;
  ll v = 0;
  bool first_zero = ( s[p] == '0' );
  while( p < (int)s.size() && ( s[p] == '0' || s[p] == '1' ) ) {
    v <<= 1;
    v += (ll)( s[p] - '0' );
    ++p;
    ++cnt;
  }
  if( first_zero && cnt != 1 ) return LLINF;
  if( cnt == 0 ) return LLINF;
  if( p < (int)s.size() && s[p] == '(' ) return LLINF;
  return v;
}

ll parse_T(int &p,string &s) {
  ll v = parse_F(p,s);
  if( v == LLINF ) return v;
  while( p < (int)s.size() && s[p] == '*' ) {
    ++p;
    ll tmp = parse_T(p,s);
    if( tmp == LLINF ) return tmp;
    v *= tmp;
  }
  return v;
}

ll parse_E(int &p,string &s) {
  ll v = parse_T(p,s);
  if( v == LLINF ) return v;
  while( p < (int)s.size() && ( s[p] == '+' || s[p] == '-' ) ) {
    char op = s[p];
    ++p;
    ll tmp = parse_T(p,s);
    if( tmp == LLINF ) return tmp;
    if( op == '+' ) v += tmp;
    if( op == '-' ) v -= tmp;
  }
  return v;
}

bool pari_check(string &s) {
  int cnt = 0;
  rep(i,(int)s.size()) {
    if( s[i] == '(' ) ++cnt;
    if( s[i] == ')' ) --cnt;
    if( cnt < 0 ) return false;
  }
  return cnt == 0;
}

bool check() {
  string s,t;
  {
    string tmp;
    tmp = context;
    rep(i,n) if( context[i] == '=' ) tmp[i] = ' ';
    vector<string> vec;
    stringstream ss;
    ss << tmp;
    while( ss >> s ) vec.push_back(s);
    if( vec.size() != 2 ) return false;
    s = vec[0];
    t = vec[1];
  }
  if( !pari_check(s) || !pari_check(t) ) return false;
  int p = 0;
  ll sv = parse_E(p,s);
  p = 0;
  ll tv = parse_E(p,t);
  if( sv == LLINF || tv == LLINF) return false;
  return sv == tv;
}

int dfs(int ptr,int used,vector<char> &already) {
  if( n <= ptr ) {
    if( debug ) {
      if( check() ) {
	cout << "succeeded : " << context << endl;
	return true;
      } else {
	//cout << "failed    : " << context << endl;
	return false;
      }
    } else {
      return check();
    }
  }
  if( !isalpha(context[ptr]) ) return dfs(ptr+1,used,already);
  int sum = 0;
  int v = context[ptr] - 'a';
  if( already[v] != '$' ) {
    if( already[v] == '=' ) return 0;
    char tmp = context[ptr];
    context[ptr] = already[v];
    sum += dfs(ptr+1,used,already);
    context[ptr] = tmp;
    return sum;
  }
  rep(i,(int)opr.size()) {
    if( ( used >> i ) & 1 ) continue;
    char tmp = context[ptr];
    context[ptr] = opr[i];
    already[v] = opr[i];
    sum += dfs(ptr+1,used|(1<<i),already);
    already[v] = '$';
    context[ptr] = tmp;
  }
  return sum;
}

bool normalize() {
  vector<char> vec;
  rep(i,(int)context.size()) if( isalpha(context[i]) ) vec.push_back(context[i]);
  sort(all(vec));
  vec.erase(unique(all(vec)),vec.end());
  rep(i,(int)context.size()) if( isalpha(context[i]) ) {
    int pos = lower_bound(all(vec),context[i]) - vec.begin();
    context[i] = (char)('a'+pos);
  }
  return (int)vec.size() <= 8;
}

void compute() {
  if( debug ) cout << "      context : " << context << endl;
  if( !normalize() ) { puts("0"); return; }
  if( debug ) cout << "fixed context : " << context << endl;
  n = (int)context.size();
  int used = 0;
  rep(i,n) if( context[i] == '=' ) { used = (1<<5); break; }
  vector<char> vec(8,'$');
  cout << dfs(0,used,vec) << endl;
}

int main() {
  if( 0 ) {
    string s;
    cin >> s;
    int p = 0;
    cout << parse_E(p,s) << endl;
    return 0;
  }
  cin >> context;
  compute();
  return 0;
}