#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
char P[2000002],str[1000000];
int main(){
    int n,f=1;
    for(int i=0;i<2000001;i++){
        if(f==1)P[i]='I';
        else P[i]='O';
        f*=-1;
    }
    while(cin>>n,n){
        int len;
        cin>>len;
        cin>>str;
        int cnt=0;
        for(int i=0;i<len;i++){
            if(i+1+2*n>m)break;
            if(!strncmp(str+i,P,n*2+1))cnt++;
        }
        cout<<cnt<<endl;
    }


}