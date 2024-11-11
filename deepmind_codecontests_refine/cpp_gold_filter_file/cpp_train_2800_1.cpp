#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#define FI first
#define SE second
#define PB push_back
#define MT make_tuple
#define int long long
using namespace std;

int N,K;
int fld[105][105][105];
int X1[55],X2[55],Y1[55],Y2[55],Z1[55],Z2[55];
vector<int> X,Y,Z;

vector<int> compress(int *x1,int *x2){
    vector<int> xs;
    for(int i=0;i<N;++i){
        xs.PB(x1[i]);
        xs.PB(x2[i]);
    }
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    for(int i=0;i<N;++i){
        x1[i]=lower_bound(xs.begin(),xs.end(),x1[i])-xs.begin();
        x2[i]=lower_bound(xs.begin(),xs.end(),x2[i])-xs.begin();
    }
    vector<int> length;
    for(int i=0;i<xs.size()-1;++i){
        length.PB(xs[i+1]-xs[i]);
    }
    return length;
}


signed main(){
    cin>>N>>K;
    for(int i=0;i<N;++i)cin>>X1[i]>>Y1[i]>>Z1[i]>>X2[i]>>Y2[i]>>Z2[i];
    X=compress(X1,X2);
    Y=compress(Y1,Y2);
    Z=compress(Z1,Z2);
    for(int i=0;i<N;++i){
        for(int x=X1[i];x<X2[i];++x){
            for(int y=Y1[i];y<Y2[i];++y){
                for(int z=Z1[i];z<Z2[i];++z){
                    fld[x][y][z]++;
                }
            }
        }
    }
    int ans=0;
    for(int x=0;x<X.size();++x){
        for(int y=0;y<Y.size();++y){
            for(int z=0;z<Z.size();++z){
                if(fld[x][y][z]>=K)ans+=X[x]*Y[y]*Z[z];
            }
        }
    }
    cout<<ans<<endl;
}