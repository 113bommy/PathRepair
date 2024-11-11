#include <iostream>

using namespace std;

int A[5];

int main() {
for(int i=0;i<3;i++) {
int x,y;
cin >> x >> y;
A[x]++;
A[y]++;
}
bool flag = true;
for(int i=1;i<5;i++) if(A[i]>2) flag = false;
if(flag) cout << "YES\n";
else cout << "NO\n";
return 0;
}
