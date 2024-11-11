#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    float x1,y1,x2,y2,x3,y3,x4,y4;
    for(int i=0;i<n;i++){
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        if((y2-y1)/(x2-x1)==(y4-y3)/(x4-x3)){
        cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}