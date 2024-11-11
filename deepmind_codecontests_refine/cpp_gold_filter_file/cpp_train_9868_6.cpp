#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,r;
    scanf("%d%d",&n,&r);
    printf("%d",r+max(0,(10-n))*100);
}
