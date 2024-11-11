#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;
bool latte(int n){
    stringstream ss;
    ss<<n;
    string str;
    ss>>str;
    string rev=str;
    reverse(rev.begin(),rev.end());
    return str==rev;
}
 int intAbs(int a){
    if(a<0)a*=-1;
    return a;
}
int main(){
    int n;
    cin>>n;
    int Min=10000000,MinNum;
    for(int i=0;i<10001;i++){
        if(!latte(i))continue;
        if(intAbs(n-i)<Min){
            Min=intAbs(n-i);
            MinNum=i;
        }
    }
    cout<<MinNum<<endl;
    return 0;
}