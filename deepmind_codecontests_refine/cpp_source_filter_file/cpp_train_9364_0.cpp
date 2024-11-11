#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>
#include<stack>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<string> vstring;
typedef vector<pint> vpint;

struct Edge{int to,from,cost;};

#ifdef DEBUG
#define debug cout
#else
stringstream __ss__;
#define debug __ss__
#endif

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) debug << *i << " "; debug << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

#define rep(i,n) for(int i=0;i<(n);++i)
#define repd(i,n) for(int i=(n)-1;i>=0;i--)
#define repn(i,m,n) for(int i=(m);i<=(n);++i)
#define repnd(i,m,n) for(int i=(n)-1;i>=(m);i--)
#define rep0(i,n) for(i=0;i<(n);++i)
#define all(n) n.begin(),n.end()
#define sz(n) ((int)(n).size())
#define IL for(;;)
#define MP make_pair
#define PB push_back
#define SS stringstream
#define X second
#define Y first
#define PUTLINE debug<<"LINE:"<<__LINE__<<endl;

const int INF = 2147483647/3;
const double EPS = 1e-10;
const double PI = acos(-1.0);

const int dx[]={1,-1,0,0,1,-1,1,-1,0};
const int dy[]={0,0,1,-1,1,-1,-1,1,0};

map<char,int> m;

bool op(string s[]){
	rep(i,5)rep(j,5)if(i!=j){
		if(s[i][0]==s[j][0])return true;
	}
	return false;
}

bool tp(string s[]){
	rep(i,5)rep(j,5)rep(k,5)rep(l,5){
		if(i==j)continue;
		if(i==k)continue;
		if(i==l)continue;
		if(j==k)continue;
		if(j==l)continue;
		if(k==l)continue;
		if(s[i][0]==s[j][0]&&s[k][0]==s[l][0])return true;
	}
	return false;
}

bool tc(string s[]){
	rep(i,5)rep(j,5)rep(k,5){
		if(i==j)continue;
		if(i==k)continue;
		if(j==k)continue;
		if(s[i][0]!=s[j][0])continue;
		if(s[i][0]!=s[k][0])continue;
		return true;
	}
	return false;
}

bool ts(string s[]){
	int i;
	rep0(i,5)if(s[i][0]=='A')break;
	if(i==5)return false;
	rep0(i,5)if(s[i][0]=='K')break;
	if(i==5)return false;
	rep0(i,5)if(s[i][0]=='Q')break;
	if(i==5)return false;
	rep0(i,5)if(s[i][0]=='J')break;
	if(i==5)return false;
	rep0(i,5)if(s[i][0]=='T')break;
	if(i==5)return false;
	return true;
}

bool st(string s[]){
	if(ts(s))return true;
	int bit=0;
	rep(i,5)bit|=1<<m[s[i][0]];
	while(bit!=0){
		if(bit==31)return true;
		bit/=2;
	}
	return false;
}

bool fl(string s[]){
	if(s[0][1]!=s[1][1])return false;
	if(s[0][1]!=s[2][1])return false;
	if(s[0][1]!=s[3][1])return false;
	if(s[0][1]!=s[4][1])return false;
	return true;
}

bool fh(string s[]){
	if(s[0][0]==s[1][0]&&s[2][0]==s[3][0]&&s[2][0]==s[4][0])return true;
	if(s[0][0]==s[2][0]&&s[1][0]==s[3][0]&&s[1][0]==s[4][0])return true;
	if(s[0][0]==s[3][0]&&s[1][0]==s[2][0]&&s[1][0]==s[4][0])return true;
	if(s[0][0]==s[4][0]&&s[1][0]==s[2][0]&&s[1][0]==s[3][0])return true;
	if(s[1][0]==s[2][0]&&s[0][0]==s[3][0]&&s[0][0]==s[4][0])return true;
	if(s[1][0]==s[3][0]&&s[0][0]==s[2][0]&&s[0][0]==s[4][0])return true;
	if(s[1][0]==s[4][0]&&s[0][0]==s[2][0]&&s[0][0]==s[3][0])return true;
	if(s[2][0]==s[3][0]&&s[0][0]==s[1][0]&&s[0][0]==s[4][0])return true;
	if(s[2][0]==s[4][0]&&s[0][0]==s[1][0]&&s[0][0]==s[3][0])return true;
	if(s[3][0]==s[4][0]&&s[0][0]==s[1][0]&&s[0][0]==s[2][0])return true;
	return false;
}

bool fc(string s[]){
	if(s[0][0]==s[1][0]&&s[0][0]==s[2][0]&&s[0][0]==s[3][0])return true;
	if(s[0][0]==s[1][0]&&s[0][0]==s[2][0]&&s[0][0]==s[4][0])return true;
	if(s[0][0]==s[1][0]&&s[0][0]==s[3][0]&&s[0][0]==s[4][0])return true;
	if(s[0][0]==s[2][0]&&s[0][0]==s[3][0]&&s[0][0]==s[4][0])return true;
	if(s[1][0]==s[2][0]&&s[1][0]==s[3][0]&&s[1][0]==s[4][0])return true;
	return false;
}

bool sf(string s[]){
	if(!st(s))return false;
	return fl(s);
}

bool rs(string s[]){
	if(!ts(s))return false;
	return fl(s);
}

int main() {
	m['A']=0;
	m['2']=1;
	m['3']=2;
	m['4']=3;
	m['5']=4;
	m['6']=5;
	m['7']=6;
	m['8']=7;
	m['9']=8;
	m['T']=9;
	m['J']=10;
	m['Q']=11;
	m['K']=12;
	m['S']=0;
	m['C']=1;
	m['H']=2;
	m['D']=3;
	int n;
	bool first=true;
	while(cin>>n){
		if(!first)cout<<endl;
		first=false;
		int x[4][13];
		rep(i,4)rep(j,13)cin>>x[i][j];
		int y[9];
		rep(i,9)cin>>y[i];
		string cards[5];
		rep(a,n){
			rep(i,5)cin>>cards[i];
rep(i,5)debug<<cards[i]<<endl;
			int ki=0;
			rep(i,5)ki+=x[m[cards[i][1]]][m[cards[i][0]]];
debug<<"ki : "<<ki<<endl;
			if(rs(cards)){
				cout<<ki*y[8]<<endl;
				continue;
			}
			if(sf(cards)){
				cout<<ki*y[7]<<endl;
				continue;
			}
			if(fc(cards)){
				cout<<ki*y[6]<<endl;
				continue;
			}
			if(fh(cards)){
				cout<<ki*y[5]<<endl;
				continue;
			}
			if(fl(cards)){
				cout<<ki*y[4]<<endl;
				continue;
			}
			if(st(cards)){
				cout<<ki*y[3]<<endl;
				continue;
			}
			if(tc(cards)){
				cout<<ki*y[2]<<endl;
				continue;
			}
			if(tp(cards)){
				cout<<ki*y[1]<<endl;
				continue;
			}
			if(op(cards)){
				cout<<ki*y[0]<<endl;
				continue;
			}
			cout<<0<<endll;
		}
	}
	return 0;
}