#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
 
using namespace std;
 
#define rep(i,n) for(int i=0; i<(n); i++)
#define repc(i,s,e) for(int i=(s); i<(e); i++)
#define pb(n) push_back((n))
#define mp(n,m) make_pair((n),(m))
#define all(r) r.begin(),r.end()
#define fi first
#define se second
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
 
const int INF = 10000000;
const int mod = 1e9 + 7;
const double EPS = 1e-9;


int main(){
	int n, t, ans;
	while(cin>>n && n > 0){
		map<int,int> mp;
		for(int i = 0; i < n; i++){
			cin>>t;
			++mp[t];
		}
		ans = -1;
		for(auto it = mp.begin(); it != mp.end(); ++it){
			if(it->se*2>n) ans = it->fi;
		}
		if(ans == -1) cout<<"NO COLOR"<<endl;
		else cout<<ans<<endl;
	}
}	