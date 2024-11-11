#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
#define mp make_pair
#define ld long double
#define PI pair<int,int>
#define fi first
#define se second
#define pol vector<poly>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=15,mod=1000000007;
struct poly{
	ull a[1<<N|2];
	poly(){
		memset(a,0,sizeof(a));
	}
	void clear(){
		memset(a,0,sizeof(a));
	}
	inline ull& operator [](int x){
		return a[x];
	}
	void fwt(int n){
		for(int i=0;i<n;i++){
			for(int j=0;j<(1<<n);j++)if(j>>i&1){
				a[j]=a[j]+a[j^(1<<i)]>=mod?a[j]+a[j^(1<<i)]-mod:a[j]+a[j^(1<<i)];
			}
		}
	}
	void ufwt(int n){
		for(int i=0;i<n;i++){
			for(int j=0;j<(1<<n);j++)if(j>>i&1){
				a[j]=a[j]>=a[j^(1<<i)]?a[j]-a[j^(1<<i)]:a[j]+mod-a[j^(1<<i)];
			}
		}
	}
}f[N+1],g[N+1];
PI Q[105];
ll v[105];
int cnt[1<<N|2];
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
void fft(pol &a,pol &b){
	int q=a.size()-1; 
	pol c(q+1);
	for(int i=0;i<=q;i++){
		//for(int k=0;k<(1<<q);k++)cout<<c[i][k]<<" "; puts("");
		for(int j=0;j<=i;j++){
			for(int k=0;k<(1<<q);k++){
				c[i][k]+=a[j][k]*b[i-j][k]; 
				//if(c[i][k]<0){cout<<q<<" "<<a[j][k]<<" "<<b[i-j][k]<<" "<<c[i][k]<<endl; exit(0);}
			}
		}
		for(int k=0;k<(1<<q);k++)c[i][k]%=mod;
	}
	swap(c,a);
}
void pf(pol &a){
	fft(a,a);
}
ll calc(int len){
	return (ksm(10,len)-1)*ksm(9,mod-2)%mod;
}
int main(){
	int n=read(),q=read();
	for(int i=0;i<q;i++){
		Q[i]=mp(read()-1,i);
		Q[i+q]=mp(read(),i);
	}
	sort(&Q[0],&Q[2*q]); Q[2*q].second=q;
	for(int i=0;i<2*q;i++){
		if(i==2*q-1)v[i]=ksm(10,n-Q[i].fi); else v[i]=calc(Q[i+1].fi-Q[i].fi); 
	}
	pol f(q+1);
	for(int i=0;i<(1<<q);i++){
		if(i)cnt[i]=cnt[i>>1]+(i&1);
		f[cnt[i]][i]=1;
		for(int j=0;j<2*q;j++)if(i>>Q[j].se&1){
			//if(i==3)cout<<v[j]<<" fjzzq "<<(i>>Q[j+1].se&1)<<endl;
			f[cnt[i]][i]=f[cnt[i]][i]*(v[j]+(i>>Q[j+1].se&1))%mod;
		}
		//cout<<f[cnt[i]][i]<<" "<<i<<endl;
	}
	for(int i=0;i<=q;i++)f[i].fwt(q);
	//pf(f); f[q].ufwt(q);
	pol ans=f;
	pf(f); pf(f); pf(f);
	fft(ans,f);//ans[q].ufwt(q);cout<<ans[q][(1<<q)-1]<<endl;
	ans[q].ufwt(q);
	ll an=ans[q][(1<<q)-1]*ksm(9,mod-2)%mod,t=calc(Q[0].fi);
	cout<<((9*t+1)%mod*an%mod+mod)%mod<<endl;
}