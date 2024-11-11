#include <bits/stdc++.h>
using namespace std;
//debug
#ifdef grief
#define debug(...) do{\
	fprintf(stderr , "%s - %d : (%s) = " , __PRETTY_FUNCTION__ , __LINE__ , #__VA_ARGS__ );\
	_DO(__VA_ARGS__);\
}while(0)
template<typename I> 				void _DO(I&&x){	cerr<<x<<endl;	}
template<typename I,typename...T>	void _DO(I&&x,T&&...tail){	cerr<<x<<" , ";	_DO(tail...);	}
template<typename _a,typename _b> 	ostream& operator << (ostream &_s,const pair<_a,_b> &_p)
{	return _s<<'('<<_p.first<<','<<_p.second<<')';	}
#define IOS
#else
#define debug(...)
#define IOS do{ios_base::sync_with_stdio(0); cin.tie(0);}while(0);
#endif
//type
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef priority_queue<pll,vector<pll>,greater<pll> > heap;
//macro
#define SZ(x) ((ll)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define stp setprecision(30)<<fixed
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MAX=1e5+5,Mlg=__lg(MAX)+2;
const ll MOD=1e9+7;
//}}}
double arr[260];
int main(){
	IOS
	int n;	cin>>n;
	while(n--){
		double sum=0;
	    int ma = 0;
		for(int i=0;i<250;i++){
			cin>>arr[i];
			sum+=arr[i];
			ma = max(ma, (int)arr[i]);
		}
		double mu=sum/250;
		cout << min(max(int(mu + 0.5), 10), 1000) << '\n';
		double var=0;
		for(int i=0;i<250;i++)
			var+=(arr[i]-mu)*(arr[i]-mu);
		var/=250;
		if(abs(mu-var) < abs(var-mu*mu/3 ))  {
// 			cout<<"poisson\n";
            cout << min(max(int(mu + 0.5), 10), 1000) << '\n';
		}
		else{
		    cout << ma / 2 << '\n';
		}
	}
	return 0;
}