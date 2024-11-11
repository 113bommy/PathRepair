#include <bit/stdc++.h> 
#define REP(i,n) for(int i=0; i< (n); ++i)
#define FOR(i,s,n) for(int i=s; i< (n); ++i)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
 
    cout << fixed << setprecision(30);
 
    while (true){
        int N, M; cin >> N >> M;
        if (N == 0) break;
        int r; cin >> r;
 
        vvi students(M, vi(1262, 0));
 
        REP(i, r){
            int t, n, m, s;
            cin >> t >> n >> m >> s; m--;
            if (s == 1){
                students[m][t]++;
            } else {
                students[m][t]--;
            }
        }
 
        REP(i, M) FOR(j, 1, 1262) students[i][j] += students[i][j - 1];
 
        int q; cin >> q;
        REP(i, q){
            int ts, te, m;
            cin >> ts >> te >> m; m--;
            int cnt = 0;
            FOR(j, ts, te) if (students[m][j] >= 1) cnt++;
            cout << cnt << endl;
        }
    }
    return 0;
}