#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1000000000;
#define REP(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define rep(i,n) REP(i, 0, n)
typedef pair<int, int> pint;//first : MP, second : Damage
void set_cost(vector<int>& cost, const vector<pint>& attack){
    cost[0] = 0;
    REP(i, 1, cost.size()){
        for(pint k : attack){
            int temp = k.first;
            if(i - k.second >= 0) temp += cost[i - k.second];
            cost[i] = min(cost[i], temp);
        }
    }
    return;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    while(cin >> N && N){
        int HP_MAX = -INF;
        vector<int> HP(N);
        rep(i, N){
            cin >> HP[i];
            HP_MAX = max(HP_MAX, HP[i]);
        }
        int M; cin >> M;
        vector<pint> single, all;
        rep(i, M){
            string a, b;
            int c, d;
            cin >> a >> c >> b >> d;
            if(b == "All")
              all.push_back(pint(c, d));
            else
              single.push_back(pint(c, d));
        }
        vector<int> scost(HP_MAX + 1, INF), acost(HP_MAX + 1, INF);
        set_cost(scost, single);
        set_cost(acost, all);
        ll ans = INF;
        rep(d, HP_MAX + 1){
            int sum = acost[d];
            for(int k : HP){
                int need = max(0, k - d);
                sum += scost[need];
            }
            ans = min(sum, ans);
        }
        /*
        while(true){
            int hit = INF, enemies = 0;
            for(int k : HP)
              if(k > 0) {
                  enemies++;
                  hit = min(k, hit);
              }
            if(enemies == 0) break;
            int cost, damage;
            if(acost[hit] > scost[hit] * enemies){
                cost = scost[hit];
                REP(i, hit, HP_MAX + 1) if(scost[i] != cost){ damage = i - 1; break;}
                cost *= enemies;
            }else{
                cost = acost[hit];
                REP(i, hit, HP_MAX + 1) if(acost[i] != cost){ damage = i - 1; break;}
            }
            for(int& k : HP) k -= damage;
            ans += cost;
        }*/
        
        cout << ans << endl;
    }
    return 0;
}