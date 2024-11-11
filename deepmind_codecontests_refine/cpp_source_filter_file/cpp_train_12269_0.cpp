#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <climits>
using namespace std;
using ll = long long;

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)

const ll INF = LLONG_MAX*0.9;
typedef pair<int,int> pii;
int N;
vector<pii> v;

int main(){
    ll mi = INF, ma = -INF;
    ll rMax = -INF, bMin = INF;
    cin >> N;
    v.resize(N);
    rep(i,N){
        cin >> v[i].first >> v[i].second;
        if(v[i].first > v[i].second) swap(v[i].first,v[i].second);
        mi = min(mi,v[i].first);
        ma = max(ma,v[i].second);
        rMax = max(rMax,v[i].first);
        bMin = min(bMin,v[i].second);

    }
    ll ans = (rMax - mi)* (ma-bMin);

    ll rMin = INF;
    sort(v.begin(),v.end());
    rep(i,N-1){
		rMax = max(rMax, v[i].second);
		rMin = min(rMin, v[i].second);
		ans = min(ans, (rMax - min(rMin, v[i + 1].first))*(ma - mi));
    }
    cout << ans << endl;
    return 0;
}