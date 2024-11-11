#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
#define rep(i,a,b) for(int i=a;i<(b);++i)
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

ll N,Q,x;
ll A[100010];


int main() {
    scanf("%lld%lld",&N,&Q);
    REP(i,N) scanf("%lld",&A[i]);
    REP(i,Q){
        scanf("%lld",&x);
        ll  sum = 0, ans = 0;
        int r = 0;
        REP(l,N){
            while(r < N && sum + A[r] <= x) sum += A[r++];
            ans += r - l;
            if(r==l) ++r;
            else sum -= A[l];
        }
        cout << ans << endl;
    }
    return 0;
}
