#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long a[n];
    book win=false;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2) win=true;
    }

    if(win) {
        cout<<"first";
    }
    else cout<<"second";


    

}