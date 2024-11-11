#include<bits/stdc++.h>
using namespace std;
int main(){

  int A, B, M;
 cin >> A >> B >> M;
 vector<int> a(A);
 vector<int> b(B);
 for (int i = 0; i < A; i++)cin >> a[i];
 for (int i = 0; i < B; i++)cin >> b[i];
 int minA = *min_element(a.begin(), a.end());
 int minB = *min_element(b.begin(), b.end());
 int ans = minA+minB;
 for (int i = 0; i < M; i++) {
 int x, y, c;
 cin >> x >> y >> c; x--; y--;
 ans = min(ans, a[x] + b[y] - c);
 }
 cout << ans << endl;

  
  
}

