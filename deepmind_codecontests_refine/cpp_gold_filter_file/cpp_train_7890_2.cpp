#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    char s[11];
    scanf("%d%s%d",&n,s,&k);
    for(int i=0;i<n;i++)printf("%c",s[i]==s[k-1]?s[k-1]:'*');
    printf("%c",'\n');
    return 0;
}