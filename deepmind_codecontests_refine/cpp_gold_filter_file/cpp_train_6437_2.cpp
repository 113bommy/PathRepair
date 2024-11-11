#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int ans=1<<30;
char s[100001];
int main(){
    cin>>s;
    for(int i=1;i<strlen(s);i++)
        if(s[i]!=s[i-1])
            ans=min(ans,max(i,int(strlen(s))-i));
    printf("%lld\n",min(ans,int(strlen(s))));
    return 0;
}