#include<cstdio>
#include<map>

using namespace std;
typedef pair<int,int> pp;

class UF {
    public:
    int par[300000]={};
    UF(int n) {
        for(int i=0; i<n; i++)
            par[i] = i;
    }
    int find(int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        par[x] = y;
    }
};

int main(void) {
    int n,k,l;
    scanf("%d%d%d",&n,&k,&l);
    UF road(250000), rail(250000);
    for(int i=0; i<k; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        x--, y--;
        road.unite(x,y);
    }
    for(int i=0; i<l; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        x--, y--;
        rail.unite(x,y);
    }

    map<pp,int> res;
    for(int i=0; i<n; i++)
        res[pp(road.find(i),rail.find(i))]++;

    for(int i=0; i<n; i++) {
        printf("%d%c", res[pp(road.find(i),rail.find(i))], i==n-1 ? '\n' : ' ');
    }
    return 0;
}