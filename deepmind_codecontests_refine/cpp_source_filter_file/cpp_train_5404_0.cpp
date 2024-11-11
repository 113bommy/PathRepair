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
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
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
const double PI  = acos(-1.0);

struct lit{
	char c;
	bool not;
	lit(char c,bool not):c(c),not(not){}
};

bool clause(string &exp,int &p){
	//<clause> ::= <literal>"&"<literal>"&"<literal>
	//<literal> ::= <variable> | "~"<variable>
	//<variable> ::= [a-z]|[A-z]
	vector<lit> literals;
	REP(i,3){
		bool not=false;
		if(exp[p]=='~'){
			not=true;
			p++;
		}
		assert(isalpha(exp[p]));
		literals.push_back(lit(exp[p],not));
		p++;
		if(i!=2){
			assert(exp[p]=='&');
			p++;
		}
	}
	REP(i,3){
		FOR(j,i+1,3){
			if(literals[i].c==literals[j].c&&literals[i].not!=literals[j].not){
				return false;
			}
		}
	}
	return true;
}

bool expression(string &exp,int &p){
	//<expression> ::= "("<clause>")" | "("<clause>")|("<expression>")"
	while(1){
		assert(exp[p]=='(');
		p++;
		if(clause(exp,p)){
			return true;
		}
		assert(exp[p]==')');
		p++;
		if(p>=exp.size()||exp[p]!='|'){
			break;
		}
		p++;
	}
	return false;
}

int main(){
	string exp;
	while(cin>>exp,exp!="#"){
		int p=0;
		cout<<(expression(exp,p)?"yes":"no")<<endl;
	}
}