#include<bits/stdc++.h>
using namespace std;

string sed(string s, string a, string b){

    string res;
    int S = (int)s.size();
    int A = (int)a.size();
    int B = (int)b.size();

    for(int i = 0; i < S; i++){
        if(i + A > S){
            res += s[i];
            continue;
        }
        bool flag = true;
        for(int j = i; j < i + A; j++){
            if(s[j] != a[j - i]){
                flag = false;
                break;
            }
        }
        if(flag){
            res += b;
            i += A - 1;
        }else{
            res += s[i];
        }
    }
    return res;
}

int main(){

    while(1){

        int n; cin >> n;
        if(!n) break;
        vector<string> a(n);
        vector<string> b(n);
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i];
        }
        string s, t; cin >> s >> t;

        set<string> Set;
        Set.insert(s);
        queue<pair<string, int> > q;
        q.push({s, 0});
        
        bool flag = false;

        while(!q.empty()){

            string tmp = q.front().first;
            int cost = q.front().second;
            //cout << tmp << endl;
            q.pop();

            if(tmp == t){
                cout << cost << endl;
                flag = true;
                break;
            }else if(tmp.size() >= t.size()) continue;

            for(int i = 0; i < n; i++){
                string next = sed(tmp, a[i], b[i]);
               // cout << i << " " << next << endl;
                if(Set.find(next) == Set.end() && next.size() <= t.size()){
                    Set.insert(next);
                    q.push({next, cost + 1});
                }
            }
        }
        
        if(!flag){
            cout << -1 << endl;
        }
    }
    return 0;
}
