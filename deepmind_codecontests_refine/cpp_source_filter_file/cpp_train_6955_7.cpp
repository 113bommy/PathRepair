#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string N, H, W;
    cin >> N >> H >> W;

    cout << (N - H + 1) * (N - W + 1) << endl;
}