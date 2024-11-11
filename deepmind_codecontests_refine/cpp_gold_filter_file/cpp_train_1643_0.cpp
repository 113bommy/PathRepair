#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
#define ff first
#define ss second
#define pi pair<ll,ll>
#define maxn 1000002
#define mod 1000000007

//vector<ll>adj[maxn];
//ll vis[maxn];
//ll cc[maxn];

//ll curr_cc;

ll arr[1000001];

ll f(ll x){
	ll res=0;
    while(x){
        res++;
        ll z=__builtin_popcount(x);
        x%=z;
    }
    return res;
}

int main(){
	ll n,cnt=0;
	string s;
	cin>>n>>s;
	
	for(int i=0;i<n;i++){
		cnt+=s[i]=='1';
	}
	
	vector<ll>a1(n+1,1),a2(n+1,1);
	
	for(int i=1;i<=n;i++){
		a1[i]  =  (a1[i-1]*2LL)%(cnt+1);
		if(cnt>1)
		a2[i] = (a2[i-1]*2LL)%(cnt-1);
	}
	ll x1=0,x2=0;
	for(int i=0;i<n;i++){
		x1 = (x1*2LL + (s[i] == '1'))%(cnt+1);
		
		if(cnt>1){
			x2 = (x2*2LL + (s[i] == '1'))%(cnt-1);
		}
	}
	
	for(int i=0;i<n;i++){
		if(s[i] == '1'){
			if(cnt == 1){
				cout<<"0\n";
				continue;
			}
			else{
				ll res = (x2 - a2[n-i-1] +cnt-1)%(cnt-1);
				cout<<1+ f(res)<<'\n';
			}
		}
		else{
			ll res = (x1 +a1[n-i-1])%(cnt+1);
			cout<<1+f(res)<<"\n";
		}
	}

}
	
	
	
	

