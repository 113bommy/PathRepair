#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef long long ll;

struct CHT{
	using D = ll;
	typedef pair<D,D> P;
	vector<P> deq;
	int s,sd,t;
	void init(int N){
		deq.resize(N);
		s=0,sd=0,t=0;
	}
	void add(D a,D b){		//add ax+b     a:(広義)単調減少!!!
		b=-b;
		P p(a,b);
		while(s+1<t&&check(deq[t-2],deq[t-1],p)) t--;
		deq[t++]=p;
	}
	D incr_query(D x){		//x:単調増加の時,これを繰り返し呼ぶ(間にaddが挟まるのはOK)
		x=-x;
		while(s+1<t&&f(deq[s],x)>=f(deq[s+1],x)) s++;
		return -f(deq[s],x);
	}
	D query(D x){		//x:単調減少の時,これを繰り返し呼ぶ(間にaddが挟まるのはOK)
		x=-x;
		if(sd>=t) sd=t-1;
		while(sd+1<t&&f(deq[sd],x)>=f(deq[sd+1],x)) sd++;
		while(sd>0&&f(deq[sd],x)>f(deq[sd-1],x)) sd--;
		return -f(deq[sd],x);
	}
	D query(D x){
		x=-x;
		int lb=s-1,ub=t-1;
		while(ub-lb>1){
			int m=(lb+ub)/2;
			if(isright(deq[m],deq[m+1],x)) lb=m;
			else ub=m;
		}
		return -f(deq[ub],x);
	}

	bool isright(P& a,P& b,D x){
		return f(a,x)>=f(b,x);
	}
	bool check(P& a,P& b,P& c){
		return (b.fs-a.fs)*(c.sc-b.sc)>=(b.sc-a.sc)*(c.fs-b.fs);
	}
	D f(P &p,int x){
		return p.fs*x+p.sc;
	}
}cht;

ll inf=1e18;
const int MN=300000;
int N;
ll T[MN];

ll le[MN+1],ri[MN+1];

ll notuse[MN];
ll use[MN];

void calc(int L,int R){
	if(L==R) return;
	int m=(L+R)/2;
	
	//L<=j<=m<=p<i<=R
	cht.init(m-L+1);
	for(ll j=L;j<=m;j++) cht.add(-j,le[j]+(j*j-j)/2);
	ll mx=-inf;
	for(ll i=R;i>=m+1;i--){
		ll val=cht.incr_query(i)+(i*i+i)/2+ri[N-i];
		chmax(mx,val);
		chmax(use[i-1],mx);
	}

	//L<=j<=p<m<i<=R
	cht.init(R-m);
	for(ll i=m+1;i<=R;i++) cht.add(-i,ri[N-i]+(i*i+i)/2);
	mx=-inf;
	for(ll j=L;j<m;j++){
		ll val=cht.query(j)+(j*j-j)/2+le[j];
		chmax(mx,val);
		chmax(use[j],mx);
	}

	calc(L,m);
	calc(m+1,R);
}
int main(){
	cin>>N;
	rep(i,N) cin>>T[i];

	cht.init(N);
	le[0]=0;
	for(ll i=0;i<N;i++){
		cht.add(-i,le[i]+(i*i-i)/2);
		le[i+1]=max(le[i]+T[i],cht.query(i+1)+(i+1)*(i+2)/2);
	}
	cht.init(N);
	ri[0]=0;
	for(ll i=0;i<N;i++){
		cht.add(-i,ri[i]+(i*i-i)/2);
		ri[i+1]=max(ri[i]+T[N-1-i],cht.query(i+1)+(i+1)*(i+2)/2);
	}
	
	rep(i,N) notuse[i]=le[i]+T[i]+ri[N-1-i];

	ll sum=0;
	rep(i,N) sum+=T[i];

	calc(0,N);

//	rep(i,N) printf("use[%d]=%lld\n",i,use[i]);
//	rep(i,N) printf("notuse[%d]=%lld\n",i,notuse[i]);
	

	int M;
	cin>>M;
	rep(i,M){
		int p;
		ll x;
		cin>>p>>x;
		p--;
		ll ans=max(use[p],notuse[p]-T[p]+x);
		cout<<ans-(sum-T[p]+x)<<endl;
	}
}
