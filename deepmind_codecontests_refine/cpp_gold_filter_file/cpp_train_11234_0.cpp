#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl;
typedef string::const_iterator State;
string s;
int reff;
string expr(State& be){
	string ret;
	while(true){
		int x=1;
		if(isdigit(*be)){
			x=0;
			while(isdigit(*be)){
				x*=10;
				x+=(*be)-'0';
				be++;
			}
		}
		if(*be=='('){
			be++;
			string t=expr(be);
			rep(i,x){
				if(ret.size()>reff) break;
				ret+=t;
			}
			be++;
		}else if('A'<=*be && *be<='Z'){
			rep(i,x){
				if(ret.size()>reff) break;
				ret+=(*be);
			}
			be++;
		}else break;
		if(ret.size()>reff) break;
	}
	return ret;
}
int main(){
	while(true){
		cin>>s>>reff;
		if(s[0]=='0') break;
		State be=s.begin();
		string t=expr(be);
		if(t.size()<=reff) cout << "0\n";
		else cout << t[reff]<<endl;
	}
}