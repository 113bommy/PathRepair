#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N;
cin >> N;
vector<int> d(N);
for (int i=0 ;i<N;i++){
cin >> d[i];
}
int S=0;
for(int i=0;i<N-1;i++){
for(int j=i+1;j<N;J++){
S = S + d[i]*d[j];
}
}
cout << S <<endl;
}