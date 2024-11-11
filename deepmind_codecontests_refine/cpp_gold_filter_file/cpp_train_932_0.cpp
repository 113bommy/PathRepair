#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

const int inf=1e9;
const int64_t inf64=1e18;
const double eps=1e-9;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

template<class T> class segtree{
public:
    int n,size_;
    vector<T> dat;
    function<T(T,T)> fun_;
    T id_;
    segtree()=default;
    segtree(int size,function<T(T,T)> fun,T id,T initial_value){ init(size,fun,id,initial_value); }
    void init(int size,function<T(T,T)> fun,T id,T initial_value){
        size_=size;
        fun_=fun;
        id_=id;
        n=1;
        while(n<size) n*=2;
        dat.assign(2*n-1,id);
        for(int i=0; i<size; ++i) update(i,initial_value);
    }
    int size()const{ return size_; }
    void update(int k, T a) {
        k+=n-1; // leaf
        dat[k]=a;
        while(k>0) {
            k=(k-1)/2;
            dat[k]=fun_(dat[k*2+1],dat[k*2+2]);
        }
    }
    T at(int index){ return dat[index+n-1]; }
    void add(int k,T a){ update(k,at(k)+a); }
    T query(int a,int b) { return query(a,b,0,0,n); }
    T query(int a,int b,int k,int l,int r) {
        if(r<=a or b<=l) return id_;
        if(a<=l and r<=b) return dat[k];
        int m=(l+r)/2;
        return fun_(query(a,b,k*2+1,l,m),query(a,b,k*2+2,m,r));
    }
};

vector<int> suffix_array(const string &s){
    const int n=s.size();
    vector<int> rank(n+1),sa(n+1),tmp(n+1);
    for(int i=0; i<=n; ++i){
        sa[i]=i;
        rank[i]=i<n?s[i]:-1;
    }
    for(int k=1; k<=n; k*=2){
        auto compare=[&](int i,int j){
            if(rank[i]!=rank[j]) return rank[i]<rank[j];
            else{
                int ri=i+k<=n?rank[i+k]:-1;
                int rj=j+k<=n?rank[j+k]:-1;
                return ri<rj;
            }
        };
        sort(sa.begin(),sa.end(),compare);
        tmp[sa[0]]=0;
        for(int i=1; i<=n; ++i){
            tmp[sa[i]]=tmp[sa[i-1]]+(compare(sa[i-1],sa[i])?1:0);
        }
        for(int i=0; i<=n; ++i){
            rank[i]=tmp[i];
        }
    }
    return sa;
}

void solve(){
    string s1,s2;
    int m;
    cin >> s1 >> m;
    s2=s1;
    reverse(s2.begin(),s2.end());
    vector<int> sa1=suffix_array(s1),sa2=suffix_array(s2);
    segtree<int> seg1(sa1.size(),[](int x,int y){return min(x,y);},inf,inf),seg2(sa1.size(),[](int x,int y){return min(x,y);},inf,inf);
    rep(i,0,sa1.size()){
        seg1.update(i,sa1[i]);
        seg2.update(i,sa2[i]);
    }
    auto ok1=[](string &s,vector<int> &sa,int index,string &x){
        return s.compare(sa[index],x.size(),x)>=0;
    };
    auto ok2=[&ok1](string &s,vector<int> &sa,int index,string &x){
        return s.compare(sa[index],x.size(),x)>0;
    };
    rep(i,0,m){
        string x,y;
        cin >> x >> y;
        reverse(y.begin(),y.end());
        if(!ok1(s1,sa1,sa1.size()-1,x) or !ok1(s2,sa2,sa2.size()-1,y)){
            cout << 0 << endl;
            continue;
        }
        int pre,suf;
        {
            int l,r;
            {
                int lb=-1,ub=sa1.size()-1;
                while(ub-lb>1){
                    int m=(lb+ub)/2;
                    if(ok1(s1,sa1,m,x)) ub=m;
                    else lb=m;
                }
                l=ub;
            }
            {
                int lb=0,ub=sa1.size();
                while(ub-lb>1){
                    int m=(lb+ub)/2;
                    if(ok2(s1,sa1,m,x)) ub=m;
                    else lb=m;
                }
                r=ub;
            }
            pre=seg1.query(l,r);
        }
        {
            int l,r;
            {
                int lb=-1,ub=sa2.size()-1;
                while(ub-lb>1){
                    int m=(lb+ub)/2;
                    if(ok1(s2,sa2,m,y)) ub=m;
                    else lb=m;
                }
                l=ub;
            }
            {
                int lb=0,ub=sa2.size();
                while(ub-lb>1){
                    int m=(lb+ub)/2;
                    if(ok2(s2,sa2,m,y)) ub=m;
                    else lb=m;
                }
                r=ub;
            }
            suf=s1.size()-seg2.query(l,r);
        }
        if(pre+x.size()>suf) cout << 0 << endl;
        else cout << max(0,suf-pre) << endl;
    }
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}