#include<bits/stdc++.h>
using namespace std;

using ld=long double;
using P=complex<ld>;
struct Line{
    P a,b;
};
vector<P> ps;
int m;
const ld EPS=1e-9;
ld cross(P a,P b){
    return a.real()*b.imag()-a.imag()*b.real();
}
int solve(int id,vector<int> flag){
    if(id==m){
        
        vector<Line> lines(m/2);
        for(int i=1;i<=m/2;i++){
            for(int j=0;j<m;j++){
                if(flag[j]==i){
                    lines[i-1].a=ps[j];
                    j++;
                    for(;j<m;j++){
                        if(flag[j]==i){
                            lines[i-1].b=ps[j];
                            break;
                        }
                        
                    }
                    break;
                }
            }
        }    
        int res=0;
        for(int i=0;i<m/2;i++){
            for(int j=0;j<i;j++){
                if(abs(cross(lines[i].a-lines[i].b,lines[j].a-lines[j].b))<EPS){
                    res++;
                }
            }
        }  

        return res;
    }
    if(flag[id]) return solve(id+1,flag);
    int res=0;
    int nex=1+*max_element(flag.begin(),flag.end());
    flag[id]=nex;
    for(int i=id+1;i<m;i++){
        if(!flag[i]){
            flag[i]=nex;
            res=max(res,solve(id+1,flag));
            flag[i]=0;
        }
    }
    return res;
}
int main(){
    cin>>m;
    ps.resize(m);
    for(int i=0;i<m;i++){
        ld x,y; cin>>x>>y;
        ps[i]={x,y};
    }
    vector<int> flag(m);
    cout<<solve(0,flag)<<endl;
    return 0;
}
