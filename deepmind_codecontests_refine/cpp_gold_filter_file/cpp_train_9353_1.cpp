#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

/*座標0を軸としてアリの順番が何匹ずれたかだけを記憶し、順番は考慮せずにアリが存在する位置を計算。
アリが座標0を通るたびにアリの順番をずらす。
位置をソートしたのち、アリがずれた分だけ配列をずらして出力。*/
int main(void){
    int N, L, T, x, w, gap;
    cin >> N >> L >> T;
    vector<int> X;
    rep(i,N){
        cin >> x >> w;
        x += ((w+1) % 3 - 1) * T;
        gap += x / L;
        if(x < 0 && x % L != 0)gap--;
        X.emplace_back(((x % L) + L) % L);
    }
    sort(X.begin(), X.end()); 
    rep(i,N)cout << X[(((gap + i) % N) + N) % N] << endl;
    return 0;
}