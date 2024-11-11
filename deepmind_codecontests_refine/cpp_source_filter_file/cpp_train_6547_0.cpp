#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
const int N=1e5+10;
int main(){
    int n,a[N];
    long long int ans=0;
    set<int> s;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=1;i<=a[n-1];i++)if(a[n-1]%i==0)s.insert(i);
    for(int i=0;i<n;i++)ans+=s.lower_bound(a[i])-a[i];
    printf("%lld\n",ans);
}
