#include<bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
    for(int i=0;i<4;i++){
        cin>>a[i];
    }
    sort(a,a+4);
    if(a[0]==1&&a[1]==4&&a[2]==7&&a[3]== 9){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}
