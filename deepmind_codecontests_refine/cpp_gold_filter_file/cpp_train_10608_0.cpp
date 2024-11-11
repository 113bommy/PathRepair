#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define space << " " <<
#define END << endl
#define pb push_back
#define fo(i,n) for(int i = 0; i<n; ++i)
#define ff(i,n) for(int i = 1; i<n; ++i)

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,pii> pi;
typedef long long ll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> pl;
typedef vector<pil>vil;

const int N = 4002;

short board[N][N] , U[N][N] , L[N][N] , R[N][N] , D[N][N];
int bit[N][2];
ll ans = 0; int h,w,p,l;

void update(int u,int id,int val) {
    while(u < N) { bit[u][id] += val; u += (u & (-u)); }
}
int get(int u,int id) {
    int ans = 0; while(u > 0) { ans += bit[u][id]; u -= (u & (-u)); } return ans;
}
void up(int id , int le , int ri) {
    if(le > ri) return;
    update(le,id,1); update(ri+1,id,-1);
}

void work(int x,int y)
{
    vector< pair<int,pii> > a; fo(i,N) fo(j,3) bit[i][j] = 0;
    while(x <= h && y <= w ) {
        a.push_back(mp(min(L[x][y],U[x][y]),mp(1,x)));
        a.push_back(mp(min(R[x][y],D[x][y]),mp(0,x)));
        x++; y++;
    } sort(a.begin(),a.end());
    fo(i,a.size()) {
        pair<int,pii> u = a[i];
        if(u.nd.st == 1)
        {
            ans += 1LL * get(u.nd.nd , 1);
            up(0,u.nd.nd - u.st + 1 , u.nd.nd - l + 1);
        }
        else
        {
            ans += 1LL * get(u.nd.nd , 0);
            up(1,u.nd.nd + l - 1 , u.nd.nd + u.st - 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> h >> w >> l >> p;
    fo(i,p) { int u,v; cin >> u >> v; board[u][v] = 1; }
    ff(i,h+1) ff(j,w+1) { if(board[i][j]) { L[i][j] = U[i][j] = 0; } else { L[i][j] = L[i][j-1] + 1; U[i][j] = U[i-1][j] + 1; } }
    for(int i=h; i >= 1; --i) for(int j=w; j>= 1; --j) {
        if(board[i][j]) { R[i][j] = D[i][j] = 0; } else { R[i][j] = R[i][j+1] + 1; D[i][j] = D[i+1][j] + 1; }
    }
    ff(i,h+1) work(i,1); for(int j=2; j<=w; ++j) work(1,j); cout << ans << endl;
}