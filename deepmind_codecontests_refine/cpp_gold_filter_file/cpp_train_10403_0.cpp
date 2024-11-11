#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s); sin>>v; return v;}
template<class T> inline string toString(T x) {ostringstream sout; sout << x; return sout.str();}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define EACH(t,i,c) for(t::iterator i=(c).begin(); i!=(c).end(); ++i)
const double EPS = 1e-10;
const double PI = acos(-1.0);

bool ok(vs &P,int r,int c,int s){
	int oR=0,oc=0,os=0;
	REP(lineno,P.size()){
		string line=P[lineno];
		int num_indent=0;
		REP(chno,line.size()){
			if(line[chno]=='.'){
				num_indent++;
			}else{
				break;
			}
		}
		if(num_indent!=oR*r+oc*c+os*s){
			return false;
		}
		REP(chno,line.size()){
			char c=line[chno];
			switch(c){
			case '(':
				oR++;break;
			case '{':
				oc++;break;
			case '[':
				os++;break;
			case ')':
				oR--;break;
			case '}':
				oc--;break;
			case ']':
				os--;break;
			}
		}
	}
	return true;
}

struct indent{
	int r,c,s;
	indent(int r,int c,int s):r(r),c(c),s(s){}
};

int main(){
	int p,q;
	while(cin>>p>>q,p|q){
		vs P(p);
		REP(i,p){
			cin>>P[i];
		}
		vs Q(q);
		REP(i,q){
			cin>>Q[i];
		}
		vector<indent> valid_indents;
		FOR(r,1,20+1){
			FOR(c,1,20+1){
				FOR(s,1,20+1){
					if(ok(P,r,c,s)){
						valid_indents.push_back(indent(r,c,s));
					}
				}
			}
		}
		int oR=0,oc=0,os=0;
		REP(i,q){
			string line=Q[i];
			set<int> valid_total_indents;
			REP(j,valid_indents.size()){
				int total_indent=0;
				total_indent+=oR*valid_indents[j].r;
				total_indent+=oc*valid_indents[j].c;
				total_indent+=os*valid_indents[j].s;
				valid_total_indents.insert(total_indent);
			}
			if(valid_total_indents.size()==1){
				cout<<(i==0?"":" ")<<*valid_total_indents.begin();
			}else{
				cout<<(i==0?"":" ")<<-1;
			}
			REP(k,line.size()){
				switch(line[k]){
				case '(':
					oR++;break;
				case '{':
					oc++;break;
				case '[':
					os++;break;
				case ')':
					oR--;break;
				case '}':
					oc--;break;
				case ']':
					os--;break;
				}
			}
		}
		cout<<endl;
	}
}