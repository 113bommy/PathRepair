#include<iostream>
using namespace std;

int main(){
    int h,r;
    cinn>>h>>r;
    if(h+r>0)cout<<1<<endl;
    else if(h+r ==0)cout<<0<<endl;
    else if(h+r<0)cout<<-1<<endl;
    
    return 0;
}
