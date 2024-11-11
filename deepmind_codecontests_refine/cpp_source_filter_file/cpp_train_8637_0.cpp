#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000

// 🔴

// O(ElogE)

// pq<pair> はfirstが大きい順に出てくるのですか？
// s:= 開始ノード  v:= 頂点数  adjlist:= 隣接リスト (first:= コスト   second:= 行先)
vector<long long> dijk(int s, int v, vector<vector<pair<int, int> > > adjlist){
    
    priority_queue <pair<int, int> > wait;
    vector<int> result(v, INF);

    //スタート地点を追加
    result[s] = 0;
    wait.push(make_pair(0, s));

    //ダイクストラ本体
    while(!wait.empty()){    //waitが空になるまで

        int nowpoint = wait.top().second;
        int nowcost = -wait.top().first;
        wait.pop();

        if(result[nowpoint] < nowcost) continue;


        //今いる頂点と隣接しているすべての頂点をなめる
        for(int i = 0; i < adjlist[nowpoint].size(); i++){

            int nextpoint = adjlist[nowpoint][i].second;
            int nextcost = nowcost + adjlist[nowpoint][i].first;
            //現時点より安く到達できそうであれば、結果を更新して優先度付きキューに格納
            if(result[nextpoint] > nextcost){
                result[nextpoint] = nextcost;
                wait.push(make_pair(-nextcost, nextpoint));
            }
        }
    }
    
    return result;         //結果列を返す
}

int main(){

    int V, E, S, G; cin >> V >> E >> S >> G;     // V:= 頂点の数    E:= 辺の数    S:= スタートノード　　G:= ゴールノード
    S--;
    G--;
    vector<vector<pair<int, int> > > adjlist(V);      //first := コスト　second := 行先

    //入力
    for(int i = 0; i < E; i++){
        int a, b; cin >> a >> b;                    // a ,b 間に辺がある
        a--;
        b--;
        adjlist[a].push_back(make_pair(1, b));
        adjlist[b].push_back(make_pair(1, a));      
    }

    //int a, b; cin >> a >> b;
    //adjlist[a].push_back(make_pair(1, b));
    //adjlist[b].push_back(make_pair(1, a)); 
    

    vector<long long> result_S(V);                 //Sからの距離
    vector<long long> result_G(V);                 //Gからの距離
    result_S = dijk(S, V, adjlist);
    result_G = dijk(G, V, adjlist);    
    //cout << result[G] << endl;

    vector<long long> s(1000000, 0);
    vector<long long> g(1000000, 0);
    for(int i = 0; i < V; i++){

        if(result_S[i] < 10000000) s[result_S[i]]++;
        
        if(result_G[i] < 10000000) g[result_G[i]]++;        
    }

    long long ans = 0;
    long long dis = result_S[G] - 2;
    //cout << dis << endl;
    //result[S];
    for(int i = 0; dis - i >= 0; i++){
        
        //cout << i << " " << dis - i << " " << s[i] << " " << g[i] << endl;
        
        ans += s[i] * g[dis - i];
        //else ans += result_S[i] * result_G[dis - i] + result_S[dis - i] * result_G[i];
        //cout << i << ": " << result_S[i] << " " << result_G[i] << endl;
    }
    
    cout << ans << endl;
    return 0;
}
