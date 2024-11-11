#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,hh;
    int k,kk;
    int a,b,c,d;
    cin>>h>>hh>>k>>kk;
    cin>>a>>b>>c>>d;
    int x=(a*h+c*(h/10))+(b*hh+d*(hh/10));
    int y=(a*k+c*(k/10))+(b*kk+d*(kk/10));
    if(x==y){
        cout<<“even”<<endl;
    }else if(x>y){
        cout<<“hiroshi”<<endl;
    }else{
        cout<<“kenjiro”<<endl;
    }
    return 0;
}

