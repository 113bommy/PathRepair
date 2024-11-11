#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define show(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define show(x)
#endif
s
typedef long long int ll;
typedef pair<int,int> pii;
template<typename T> using vec=std::vector<T>;

const int inf=1<<30;
const long long int infll=1LL<<62;
const double eps=1e-9;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

//range add,compute range max
template<class T> class segtree{
public:
    int n,size;
    vector<T> dat,sum; //????????????,?????????????§?????¶?????????????
    segtree()=default;
    segtree(int size_,T x){ init(size_,x); }
    void init(int size_,T x){
        size=size_;
        n=1;
        while(n<size) n*=2;
        dat.assign(2*n-1,0);
        sum.assign(2*n-1,0);
        for(int i=0; i<size; ++i) add(i,i+1,x);
    }
    void add(int a,int b,T x){ add(a,b,x,0,0,n); }
    T add(int a,int b,T x,int k,int l,int r){
        if(b<=l or r<=a) return dat[k];
        if(a<=l and r<=b){
            sum[k]+=x;
            return dat[k]+=x;
        }
        int m=(l+r)/2;
        return dat[k]=max(add(a,b,x,2*k+1,l,m),add(a,b,x,2*k+2,m,r))+sum[k];
    }
    T query(int a,int b){ return query(a,b,0,0,n); }
    T query(int a,int b,int k,int l,int r){
        if(b<=l or r<=a) return numeric_limits<ll>::min();
        if(a<=l and r<=b) return dat[k];
        int m=(l+r)/2;
        return max(query(a,b,2*k+1,l,m),query(a,b,2*k+2,m,r))+sum[k];
    }
};

void solve(int q,int lim){
    map<int,int> m1,m2; //segtree?????§???index
    segtree<ll> seg(q,numeric_limits<int>::min());
    int tail=0,size=0;

    auto get_pos=[&](int x){ //?????????x??????????????????segtree?????§???index????±???????
        int lb=-1,ub=q-1;
        while(ub-lb>1){
            int m=(lb+ub)/2;
            if(seg.query(0,m+1)>=x) ub=m;
            else lb=m;
        }
        return ub;
    };

    auto erase=[&](int k){ //segtree?????§???index??§k???????????????????????????
        seg.add(k,k+1,numeric_limits<int>::min());
        seg.add(k+1,q,-1);
    };

    rep(i,0,q){
        int query,x;
        cin >> query >> x;
        if(query==0){
            if(size==lim){
                erase(get_pos(0));
                --size;
            }
            m1[x]=tail;
            m2[tail]=x;
            ll tmp=seg.query(tail,tail+1);
            seg.add(tail,tail+1,-tmp);
            seg.add(tail,tail+1,size);
            ++tail;
            ++size;
        }else if(query==1){
            erase(get_pos(x-1));
            --size;
        }else if(query==2) cout << m2[get_pos(x-1)] << endl;
        else{
            erase(m1[x]);
            --size;
        }
    }
    cout << "end" << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    while(true){
        int q,lim;
        cin >> q >> lim;
        if(q==0 and lim==0) break;
        solve(q,lim);
    }
    return 0;
}