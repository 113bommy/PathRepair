#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct SuffixArray{
  Int n,k;
  string S;
  vector<Int> sa,lcp,r2;
  SuffixArray(){}
  SuffixArray(string& S):S(S){init();}
  void init(){
    n=S.length();
    S.push_back('$');
    build_sa();
    build_lcp();
    build_rmq();
    //for(Int i=0;i<=n;i++) cout<<i<<":"<<S.substr(sa[i])<<endl;
  }
  void build_sa(){
    sa.clear();
    sa.resize(n+1,0);
    iota(sa.begin(),sa.end(),0);
    sort(sa.begin(),sa.end(),
	 [&](Int a,Int b){
	   if(S[a]==S[b]) return a>b;
	   return S[a]<S[b];
	 });
    vector<Int> c(n+1,0),r(n+1),cnt(n+1),s(n+1);
    for(Int i=0;i<=n;i++) r[i]=S[i];
    for(Int len=1;len<=n;len*=2){
      for(Int i=0;i<=n;i++){
	 c[sa[i]]=
	   i>0 &&
	   r[sa[i-1]]==r[sa[i]] &&
	   sa[i-1]+len<=n &&
	   r[sa[i-1]+len/2]==r[sa[i]+len/2] ?
	   c[sa[i-1]]:i;
      }
      iota(cnt.begin(),cnt.end(),0);
      copy(sa.begin(),sa.end(),r.begin());
      for(Int i=0;i<=n;i++){
	Int s1=r[i]-len;
	if(s1>=0) sa[cnt[c[s1]]++]=s1;
      }
      c.swap(r);
    }
  }
  
  bool lt_substr(string &T,Int si=0,Int ti=0){
    Int sn=S.size(),tn=T.size();
    while(si<sn&&ti<tn){
      if(S[si]<T[ti]) return 1;
      if(S[si]>T[ti]) return 0;
      si++;ti++;
    }
    return si>=sn&&ti<tn;
  }
  
  Int lower_bound(string& T){
    Int low=0,high=n+1;
    while(low+1<high){
      Int mid=(low+high)/2;
      if(lt_substr(T,sa[mid],0)) low=mid;
      else high=mid;
    }
    return high;
  }
  
  Int upper_bound(string& T){
    T.back()++;
    Int res=lower_bound(T);
    T.back()--;
    return res;
  }
  
  // O(|T|*log|S|)
  Int count(string& T){
    return upper_bound(T)-lower_bound(T);
  }
  
  void build_lcp(){
    lcp.clear();
    lcp.resize(n+1,0);
    r2.resize(n+1);
    for(Int i=0;i<=n;i++) r2[sa[i]]=i;
    Int h=0;
    lcp[0]=0;
    for(Int i=0;i<n;i++){
      Int j=sa[r2[i]-1];
      if(h>0) h--;
      for(;j+h<n&&i+h<n;h++){
	if(S[j+h]!=S[i+h]) break;
      }
      lcp[r2[i]-1]=h;
    }
  }
  
  Int getlcp(Int p,string &T,Int d){
    Int i=0;
    Int len=min((Int)T.length()-d,(Int)S.length()-p-d);
    while(i<len&&S[p+d+i]==T[d+i]) i++;
    return i;
  }

  struct RMQ{
    Int n;
    vector<Int> dat;
    const Int def=INT_MAX;
    RMQ(){}
    void init(Int n_){
      n=1;
      while(n<n_) n*=2;
      dat.clear();
      dat.resize(2*n-1,def);
    }
    void build(Int n_, vector<Int>& a){
      for(Int i=0;i<n_;i++) dat[i+n-1]=a[i];
      for(Int i=n-2;i>=0;i--)
	dat[i]=min(dat[i*2+1],dat[i*2+2]);
    }
    Int query(Int a,Int b,Int k,Int l,Int r){
      if(r<=a||b<=l) return def;
      if(a<=l&&r<=b) return dat[k];
      else{
	Int vl=query(a,b,k*2+1,l,(l+r)/2);
	Int vr=query(a,b,k*2+2,(l+r)/2,r);
	return min(vl,vr);
      }
    }
    Int query(Int a,Int b){
      if(a>b) swap(a,b);
      //cout<<n<<":"<<a<<" "<<b<<endl;
      return query(max(a,0),b,0,0,n);
    }
  };
  
  RMQ rmq;
  void build_rmq(){
    rmq.init(n);
    rmq.build(n,lcp);
  }
};


signed main(){
  string s;
  cin>>s;
  string t=s;
  reverse(t.begin(),t.end());
  SuffixArray sa(s),ta(t);
  auto &srmq=sa.rmq;
  auto &trmq=ta.rmq;
  Int q;
  cin>>q;
  Int n=s.size();
  for(Int i=0;i<q;i++){
    Int l,r,u;
    cin>>l>>r>>u;
    l--;
    if(r-l==u){
      cout<<"Yes"<<endl;
      continue;
    }
    //cout<<s.substr(l,r-l)<<endl;
    //cout<<string(u,' ')+s.substr(l,r-l)<<endl;
    Int x=srmq.query(sa.r2[l],sa.r2[l+u]);
    Int y=trmq.query(ta.r2[n-r],ta.r2[n-r+u]);
    if((x+1+y)>=((r-l)-u)){
      cout<<"Yes"<<endl;
      continue;
    }
    if((l+x+u)!=(r-(u+y+1))||s[l+x]!=s[r-(y+1)]){
      cout<<"No"<<endl;
      continue;
    }
    Int z=srmq.query(sa.r2[l+x+u+1],sa.r2[l+x+1]);
    if(0){
      cout<<x<<" "<<y<<endl;
      cout<<s[l+x+u]<<" "<<s[r-(y+1)]<<endl;
      cout<<s[l+x]<<" "<<s[r-(u+y+1)]<<endl;
      cout<<s.substr(l+x+u+1,((r-(y+1))-(l+x+u+1)))<<endl;
      cout<<s.substr(l+x+1,((r-(u+y+1))-(l+x+1)))<<endl;
      cout<<z<<endl;
      cout<<(x+1+z+1+y)<<" "<<((r-l)-u)<<endl;
    }
    cout<<((x+1+z+1+y>=(r-l)-u)?"Yes":"No")<<endl;
  }
  return 0;
}

