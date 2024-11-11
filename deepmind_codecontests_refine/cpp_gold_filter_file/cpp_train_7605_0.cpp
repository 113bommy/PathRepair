#include <stdio.h>
#include <set>
#include <iterator>
using namespace std;
int main(){
    int n,temp,k;
    multiset<int> s;
    multiset<int>::iterator u;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&k,&temp);
        if(k==0){
            s.insert(temp);
            printf("%ld\n",s.size());
        }
        else if(k==1)printf("%ld\n",s.count(temp));
        else if(k==2)s.erase(temp);
        else{
            u=s.lower_bound(temp);
            scanf("%d",&temp);
            while(u!=s.end()){
                if(*u>temp)break;
                printf("%d\n",*u);
                u++;
            }
        }
    }
}
