#include<bits/stdc++.h>
using namespace std;

int main(){

    int e1,e2,e3,e4;
    cin>>e1>>e2>>e3>>e4;
    if(e1==e2&&e3==e4){
       cout<<"yes"<<endl;
    } else if (e2==e3&&e1==e4){
       cout<<"yes"<<endl;
    } else if (e1==e3&&e2==e4){
       cout<<"yes"<<endl;
    } else {
       cout<<"no<"<endl;
    }
    return 0;
}
