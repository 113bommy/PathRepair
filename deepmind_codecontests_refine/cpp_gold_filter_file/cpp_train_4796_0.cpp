#include <stdio.h>
#include <vector>
using namespace std;
#define PB push_back
const int N=1e5+10;
int main(){
    int n,q,t;
    vector<int> v[N];
    scanf("%d%d",&n,&q);
    while(q--){
        scanf("%d%d",&n,&t);
        if(n==0){
            scanf("%d",&n);
            v[t].PB(n);
        }
        else if(n==1){
            if(!v[t].empty())printf("%d",v[t][0]);
            for(int i=1;i<v[t].size();i++)printf(" %d",v[t][i]);
            printf("\n");
        }
        else v[t].clear();
    }
}
