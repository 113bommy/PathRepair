#include<bits/stdc++.h>
 using namespace std;
 const int MOD = 1e9 + 7, N = 2005; 
int C[N][N]; int main() 
{  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); 
 C[0][0] = 1;
  for(int i = 1; i < N; i++)
 {    C[i][0] = 1;   
 for(int j = 1; j < N; j++) 
{      C[i][j] = C[i - 1][j] + C[i - 1][j - 1]; 
     if(C[i][j] >= MOD) C[i][j] -= MOD;    } 
 } 
 int n, k; 
cin >> n >> k; 
 for(int i = 1; i <= k; i++)
 {    cout << (1ll * C[n - k + 1][i] * C[k - 1][i - 1] % MOD) << "\n"; 
}