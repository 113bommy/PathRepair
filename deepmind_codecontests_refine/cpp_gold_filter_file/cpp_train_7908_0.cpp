#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <functional>
#include <complex>
#include <stack>
#include <tuple>
#include <array>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)


typedef long long int ll;
typedef double D;      // ??§?¨?????????????D???long D?????????
typedef complex<D> P;  // Point
typedef pair<P, P> L;  // Line
typedef vector<P> VP;


const int INF = (1<<30) - 1;
const D EPS = 1e-3;

#define X real()
#define Y imag()
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)

D abs(D x, D y, D z){
    return sqrt(x*x + y*y + z*z);
}

D dot(D a1, D a2, D a3, D b1, D b2, D b3){
    return a1*b1 + a2*b2 + a3*b3;
}

D cross(D a1, D a2, D a3, D b1, D b2, D b3){
    D i = a2*b3 - a3*b2;
    D j = a3*b1 - a1*b3;
    D k = a1*b2 - a2*b1;
    return abs(i, j, k);
}

D distLP(D sx, D sy, D sz, D dx, D dy, D dz, D px, D py, D pz){
    return abs(cross(px-sx, py-sy, pz-sz, dx-sx, dy-sy, dz-sz))/abs(dx-sx, dy-sy, dz-sz);
}

D distSP(D sx, D sy, D sz, D dx, D dy, D dz, D px, D py, D pz){
    if(LE(dot(dx-sx, dy-sy, dz-sz, px-sx, py-sy, pz-sz), 0))
        return abs(px-sx, py-sy, pz-sz);
    if(LE(dot(sx-dx, sy-dy, sz-dz, px-dx, py-dy, pz-dz), 0))
        return abs(px-dx, py-dy, pz-dz);
    return distLP(sx, sy, sz, dx, dy, dz, px, py, pz);
}

class Circle{
public:
    D x, y, z, r;
    ll l;
    
    Circle(D x, D y, D z, D r, ll l): x(x), y(y), z(z), r(r), l(l){};
    
    bool intersect(D sx, D sy, D sz, D dx, D dy, D dz){
        return LE(distSP(sx, sy, sz, dx, dy, dz, x, y, z), r);
    }
};

//g++ -std=c++0x -msse4.2 -O3
//#include <bits/stdc++.h>
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout.precision(16);
    
    int N, Q;
    cin >> N >> Q;
    vector<Circle> circles;
    for(int i=0; i<N; i++){
        D x, y, z, r;
        ll l;
        cin >> x >> y >> z >> r >> l;
        circles.push_back({x, y, z, r, l});
    }
    
    while(Q--){
        ll ans = 0;
        D sx, sy, sz, dx, dy, dz;
        cin >> sx >> sy >> sz >> dx >> dy >> dz;
        
        for(Circle &circle: circles){
            if(circle.intersect(sx, sy, sz, dx, dy, dz))
                ans += circle.l;
        }
        cout << ans << endl;
    }
    
    return 0;
}