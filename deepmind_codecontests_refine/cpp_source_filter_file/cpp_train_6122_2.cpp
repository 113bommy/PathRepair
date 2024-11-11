#include<bits\stdc++.h>
using namespace std;
#define ll long long
int N;
ll s[100010];
ll ans;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }

    for(int C = 1; C < N; C++){
        ll score = 0;
        set<int> coor;
        for(int k = 1; k * C < N; k++){
            if(N - 1 - k * C < C) break;
            int y1 = N - 1 - k * C; 
            int y2 = k * C;
            if(coor.find(y1) != coor.end() || coor.find(y2) != coor.end() || y1 == y2) break;

            coor.insert(y1);
            coor.insert(y2);
            score += s[y1] + s[y2];
            ans = max(ans, score);
        }
    }
    cout << ans << endl;
    return 0;
}