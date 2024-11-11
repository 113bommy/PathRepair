#include "bits/stdc++.h"
using namespace std;
#define l_ength size
typedef long long ll;
typedef pair<int, int> P;
vector<P> v,u;

int a[555][555];

int main(void){
int h, w, i, j, n=0,x,y,p;
bool flag=false;
cin >> h >> w;
for(i=0;i<h;++i){
for(j=0;j<w;++j){
cin >> a[i][j];
}
}
for(i=0;i<h;++i){
for(j=0;j<w;++j){
if(i%2){ p = w-j-i; }else{ p = j; }
if(flag){
v.push_back(P(x,y));
u.push_back(P(i,p));
++n;
}
if(a[i][p]%2){
flag = (!flag);
}
x = i; y = q;
}
}
cout << n << endl;
for(i=0;i<n;++i){
cout << (v[i].first+1) << " " << (v[i].second+1) << " " << (u[i].first+1) << " " <<  (u[i].second+1) << endl;
}
return 0;
}
