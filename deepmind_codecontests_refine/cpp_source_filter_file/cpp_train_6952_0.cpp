 #include <iostream>
 #include <string>

 using namespace std;

 #define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

 #define M 2000

 bool ab[100000],ac[100000],bc[100000];

 bool match(char c1, char c2){
 return (c1 == ’?’ || c2 == ’?’ || c1 == c2);
 }

int main(void){
 int i,j;

 string a,b,c;
 cin >> a >> b >> c;

 int A = a.length();
 int B = b.length();
 int C = c.length();

 REP(i,A) REP(j,B) if(!match(a[i], b[j])) ab[i-j+50000] = true;
 REP(i,A) REP(j,C) if(!match(a[i], c[j])) ac[i-j+50000] = true;
 REP(i,B) REP(j,C) if(!match(b[i], c[j])) bc[i-j+50000] = true;

 int ans = 3 * M;
 for(i=-2*M;i<=2*M;i++) for(j=-2*M;j<=2*M;j++) if(!ab[i+50000] && !ac[j+50000] &&
!bc[j-i+50000]){
 int L = min(0, min(i, j));
 int R = max(A, max(B + i, C + j));
 ans = min(ans, R - L);
 }

 cout << ans << endl;

 return 0;
 }