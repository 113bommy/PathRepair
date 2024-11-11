#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
#include<sstream>
#include<iomanip>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-8;
const int inf=1e8;
int main(){
	string s;
	while(getline(cin,s)){
		string t="";
		set<string>out,no;
		rep(i,s.size())if(isalpha(s[i]))t+=toupper(s[i]);
		rep(i,t.size())loop(j,3,t.size()+1)if(i+j<=t.size()){
			string a=t.substr(i,j),b=a;
			reverse(all(b));
			if(a==b){
				out.insert(a);
				no.insert(t.substr(i+1,j-2));
			}
		}
		vector<string>ans;
		for(set<string>::iterator it=out.begin();it!=out.end();it++)
			if(no.find(*it)==no.end())
				ans.pb(*it);
		rep(i,ans.size()){
			if(i)cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;
	}
}