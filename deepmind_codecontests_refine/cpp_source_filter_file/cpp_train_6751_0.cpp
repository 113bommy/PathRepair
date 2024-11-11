/☭
#include<cstdio>
#include<queue>
#include<map>
#include<set>
 
using namespace std;
 
const int N=1e5+10;
 
struct pai{
    int f, s;
};
 
bool operator <(pai a, pai b) {
    return (a.f==b.f)?(a.s<b.s):(a.f<b.f);
}
 
map< pai, int>m;
set<int> mu[N];
queue< pai >q;
 
int f[N], n;
 
inline void add(int x, int y) {mu[x].insert(y), mu[y].insert(x);}
 
pai marry(int x, int y) {
    if(x>y) {int t=y; y=x, x=t;}
    return (pai){x, y};
}
 
int f_f(int x){
    return f[x]?f[x]=f_f(f[x]):x;
}
 
int main(){
    scanf("%d", &n);
    for(int i=1; i<=(n<<1)-2; i++) {
        int x, y; scanf("%d%d", &x, &y), add(x, y);
        pai edg=marry(x, y); ++m[edg];
        if(m[edg]==2) q.push(edg);
        if(m[edg]>2) {puts("NO"); return 0;}
    }
    for(int w=1; w<n; w++) {
        if(q.empty()) {puts("NO"); return 0;}
        int x=0, y=0;
        while(x==y) x=f_f(q.front().f), y=f_f(q.front().s), q.pop();
        if(mu[x].size()>mu[y].size()) swap(x, y); f[x]=y;
        for(set<int>::iterator i=mu[x].begin(); i!=mu[x].end(); i++){
            int from=f_f(*i); mu[from].erase(mu[from].find(x)); if(from==y) continue;
            add(from,y); pai t=marry(from,y); m[t]++; if(m[t]==2) q.push(t);
        }
        mu[x].clear();
    }
    puts("YES");
}
