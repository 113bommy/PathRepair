#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
 
using namespace std;
 
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define mp make_pair
#define all(r) r.begin(),r.end()
#define fi first
#define se second
#define println(X) cout<<X<<endl;
#define DBG(X) cout<<#X<<" : "<<X<<endl;
 
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9;


string str[]={"linch ", "dinner ", "midnight "};

int main(){
	int n;
	while(cin>> n && n){
		int h, m1, m2; char c;
		int a, b;
		vi v(3, 0), u(3, 0);
		while(n--){
			cin>>h>>c>>m1>>m2;
			a = b = h*60;
			a += m1; b += m2 + (m1>m2?60:0);
			if(11*60<=a&&a<=14*60+59){
				u[0]++;
				if(b-a<=8) v[0]++;
			}
			else if(18*60<=a&&a<=20*60+59){
				u[1]++;
				if(b-a<=8) v[1]++;
			}
			else if((21*60<=a||a<=60+59){
				u[2]++;
				if(b-a<=8) v[2]++;
				//cout<<m1<<" "<<m2<<endl;
			}
		}
		rep(i, 3){
			cout<<str[i];
			if(u[i]==0) cout<<"no guest"<<endl;
			else cout<<v[i]*100/u[i]<<endl;
		}
	}
}