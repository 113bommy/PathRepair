// 簡易競プロテンプレ
#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[8][8];
int a,b;
int main(void){
 cin >> n >> m;
 for(int i=0;i<m;i++){cin >> a >> b; f[a-1][b-1] = f[b-1][a-1] = 1;}
 vector<int> p(n);
 for(int i=0;i<n;i++) p[i] = i;
 int ans = 0;
 do{
  if (p[0]!=0) continue;
  int ok = 1;
  for(int i=0;i+1<n;i++){if (f[p[i]][p[i+1]]==0) ok = 0;}
  if (ok) ans++;
 }while(next_permutation(p.begin(), p.end()));
 cout << ans << endl;
 return 0;
}