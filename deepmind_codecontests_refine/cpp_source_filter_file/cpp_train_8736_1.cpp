w#include<bits/stdc++.h>

using namespace std;
#define FOR(i,bg,ed) for(int i=bg;i<ed;i++)
#define REP(i,n) FOR(i,0,n)

template<typename T>
bool chmax(T& l,T r){
    bool ret = l<r;
    if(l<r)l=r;
    return ret;
}
template<typename T>
bool chmin(T& l,T r){
    bool ret = l>r;
    if(l>r)l=r;
    return ret;
}

typedef long long LL;
typedef double D;
LL d;
LL n,b;
LL p[32];
LL h[32];



D v(D vx,D vy){
    return vx*vx+vy*vy;
}
D g(D vy,D yard){
    if(vy<=0)return 1e20;
    return v(vy,yard/(2*vy)); 
}
D g(D yard){
    D lb = 0;
    D ub = 1e9;
    REP(i,100){
        const D m1 = (lb+lb+ub)/3.0;
        const D m2 = (lb+ub+ub)/3.0;
        if(g(m1,yard)<g(m2,yard)){
            ub = m2;
        }
        else{
            lb = m1;
        }
    }
    return lb;
}
D f(D m){
    D yard = d/m;
    D need = 0;
    REP(i,n){
        D x = p[i];
        while(x>yard){
            x-=yard;
        }
        D vy = (yard*h[i])
            /
            ((1.0-x/yard)*2*x);
        chmax(need,sqrt(vy));
    }
    D td = g(yard);
    if(td>=need)return g(td,yard);
    else return g(need,yard);
}

//check yard = d/m
bool check(LL m){
    REP(i,n){
        REP(j,m){
            if((j+1)*d == p[i] * m){
                return false;
            }
        }
    }
    return true;
}
        
int main(){
    D ret=1e20;
    cin>>d>>n>>b;
    REP(i,n)cin>>p[i]>>h[i];
    FOR(i,1,b+2)if(check(i)){
        chmin(ret,f(i));
    }
    cout<<fixed<<sqrt(ret)<<endl;
    return 0;
}