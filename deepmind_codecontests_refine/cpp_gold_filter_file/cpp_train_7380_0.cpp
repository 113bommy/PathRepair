#include<iostream>
#include<algorithm>
#include<cassert>
#include<map>
#include<vector>

using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int D=1;
const ll inf = 1LL<<60;

inline ll myabs(ll a,ll b){
  return max(a,b)-min(a,b);
}

inline ll mymin(ll a, ll b){
  return a < b?a:b;
}

inline ll mymax(ll a, ll b){
  return a > b?a:b;
}

inline int mymin(int a, int b){
  return a < b?a:b;
}

inline int mymax(int a, int b){
  return a > b?a:b;
}

//inline void precalc(const vector<pair<ll,ll> >  in,vector<pli> & ret){
inline vector<pll> precalc(const vector<pair<ll,ll> >  in,bool flag){
  vector<pll> ret;
  int n = in.size();
  //yåº§æ¨ã®å§ç¸®ãæå°å¤æ±ãã¦ãã
  map<ll,int> M;
  vector<ll> all;
  rep(i,(int)in.size()){
    if (flag){
      M[in[i].first]++;
      all.push_back(in[i].first);
    }else {
      M[in[i].second]++;
      all.push_back(in[i].second);
    }
  }
  sort(all.begin(),all.end());
  all.erase(unique(all.begin(),all.end()),all.end());

  //åæå¤ãè¨ç®
  int num = M[all[0]];
  ll pos = 2*num;
  ll neg = 2*(n-num);
  ll prev = all[0];
   ll cur=0;
   rep(i,(int)in.size()){
     if (flag)cur = cur + 2*((ll)in[i].first-(ll)all[0]);
     else cur = cur + 2*((ll)in[i].second-(ll)all[0]);
   }
   ret.push_back(make_pair(cur,all[0]));

   REP(i,1,all.size()){
     ll fir = all[i];
     int sec=M[all[i]];
     ll diff = fir - prev;
     cur = cur + (pos * diff);
     cur = cur - (neg * diff);
     neg=neg-(sec*2);
     pos=pos+(sec*2);
     assert(neg+pos == 2*n);
     prev = fir;
     ret.push_back(make_pair(cur,fir));
   }
   return ret;
 }

 void bf(vector<pair<ll,ll> > &in,ll tans,ll tansx,ll tansy){
   vector<ll> x,y;
   rep(i,in.size()){
     swap(in[i].second,in[i].first);
     x.push_back(in[i].second);
     y.push_back(in[i].first);
   }
   sort(x.begin(),x.end());x.erase(unique(x.begin(),x.end()),x.end());
   sort(y.begin(),y.end());y.erase(unique(y.begin(),y.end()),y.end());
   ll ans = inf;
   ll ansx,ansy;
   rep(i,y.size()){
     rep(j,x.size()){
       vector<ll> dist;
       rep(k,in.size()){
	 dist.push_back(llabs(in[k].second-x[j])+llabs(in[k].first-y[i]));
       }
       sort(dist.begin(),dist.end());
       ll tmp = 0;
       rep(k,dist.size()){
	 tmp += dist[k]*2;
       }
       tmp -= dist[dist.size()-1];
       if (tmp < ans){
	 ans = tmp;
	 ansy = x[j];
	 ansx = y[i];
       }else if (tmp == ans && x[j] < ansx){
	 ans = tmp;
	 ansx = x[j];
	 ansy = y[i];
       }else if (tmp == ans && x[j] == ansx && y[i] < ansy){
	 ans = tmp;
	 ansx = x[j];
	 ansy = y[i];
       }
     }
   }
   //cout << "brute force " << endl;
   //cout << ans <<endl << ansy <<" " << ansx << endl;
   //assert(ans == tans);
   //assert(ansx == tansy);
   //assert(ansy == tansx);
 }


 int main(){
   ll w,h;
   int n;
   while(cin>>w>>h){
     cin>>n;
     vector<pair<ll,ll> > in(n);
     //input is x,y
     rep(i,n){
       cin>>in[i].first>>in[i].second;
     }
     vector<pll> y,x;//ã¹ã³ã¢ãåº§æ¨ã®ãã¢
     map<ll,int> X,Y;
     x = precalc(in,false);
     y = precalc(in,true);

     //è§£ã
     int mx = 0,my=0;
     vector<int> mxs,mys;
     rep(i,(int)x.size()){
       X[x[i].second]=i;
       if (x[i].first < x[mx].first)mx = i;
       else if (x[i].first == x[mx].first && x[i].second < x[mx].second)mx = i;
     }
     rep(i,x.size())if (x[i].first == x[mx].first)mxs.push_back(i);
     rep(i,(int)y.size()){
       Y[y[i].second]=i;
       if (y[i].first < y[my].first)my = i;    
       else if (y[i].first == y[my].first && y[i].second < y[my].second)my = i;
     }
     rep(i,y.size())if (y[i].first == y[my].first)mys.push_back(i);
     ll ansx=-1,ansy=-1;
     ll ans = inf;
     rep(k,(int)in.size()){
       rep(ii,mys.size()){
	 rep(jj,mxs.size()){
	   REP(i,mymax(0,mys[ii]-D),mymin(mys[ii]+D,(int)y.size())){
	     REP(j,mymax(0,mxs[jj]-D),mymin(mxs[jj]+D,(int)x.size())){
	       ll tmp = y[i].first;
	       tmp = tmp + x[j].first;
	       tmp = tmp - llabs(y[i].second-in[k].first);
	       tmp = tmp - llabs(x[j].second-in[k].second); 
	       ll ty=y[i].second;
	       ll tx=x[j].second;
	       if (tmp < ans || (tmp == ans && ty < ansy) || (tmp == ans && ty == ansy && tx < ansx) ){
		 ans = tmp;
		 ansx = tx;
		 ansy = ty;
	       }
	     }
	   }
	 }
       }
       /*
      //åãé¤ãyåº§æ¨ã®ã¤ã³ããã¯ã¹,åãé¤ãåº§æ¨å°éã¯in[k].first,in[k].second
      //assert(X.find(in[k].second) != X.end() && Y.find(in[k].first) != Y.end());
      int xind = X[in[k].second];
      int yind = Y[in[k].first ];

      //ç­ãã®å ´æãæ±ºããã(i,j)
      REP(i,mymax(0,yind-5),mymin(yind+5,(int)Y.size())){
	REP(j,mymax(0,xind-5),mymin(xind+5,(int)X.size())){
	  //ç­ãã®å ´æã®ãå¾å¾©ãåãé¤ããªãã£ãå¤ãæ±ãã
	  ll tmp = (ll)y[i].first + (ll)x[j].first;
	  tmp = tmp - myabs((ll)y[i].second,(ll)in[k].first);
	  tmp = tmp - myabs((ll)x[j].second,(ll)in[k].second); 
	  ll ty=y[i].second,tx=x[j].second;
	  if (tmp < ans || (tmp == ans && ty < ansy) || (tmp == ans && ty == ansy && tx < ansx) ){
	    ans = tmp;
	    ansx = tx;
	    ansy = ty;
	  }
	}
	}*/
    }
    assert(ansx != -1);
    cout << ans << endl;
    cout << ansy <<" " << ansx << endl;
  }
}