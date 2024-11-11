#include <iostream>
using namespace std;
int h,w,x=0;
int main(){
cin>>h;
    for(int i=0;i<h;i++){cin>>w;if(w%2==0)x++;}
    cout<<x<<endl;
    return 0;
}
