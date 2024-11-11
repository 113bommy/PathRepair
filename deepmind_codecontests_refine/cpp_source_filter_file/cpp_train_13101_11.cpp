#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,c,k,ans,x,b;
int t[100005];
int main(void){
    scanf("%d%d%d",&n,&c,&k);
    for(int i=0;i<n;i++)scanf("%d"t+i);
    sort(t,t+n);
    x=c+1;
    for(int i=0;i<n;i++){
        if(++x>c||b+k<t){
            ans++;
            x=1;
            b=t;
        }
    }
    printf("%d\n",ans);
}