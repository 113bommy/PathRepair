#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(101);
    fill(v.begin(),v.end(),0)
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v[a]++;
    }
    for(int i=100;i>0;i+=-1){
        v[i-1]+=v[i];
    }
    for(int i=100;i>=0;i+=-1){
        if(v[i]<=i){
            cout<<i<<endl;
            return 0;
        }
    }
}
