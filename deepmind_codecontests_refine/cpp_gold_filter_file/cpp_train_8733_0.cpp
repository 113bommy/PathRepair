#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
char P[1000005],str[1000005];
int main(){
    int n,f=1;
    for(int i=0;i<1000000;i++){
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
            if(i+1+2*n>len)break;
            if(!strncmp(str+i,P,n*2+1))cnt++;
        }
        cout<<cnt<<endl;
    }


}