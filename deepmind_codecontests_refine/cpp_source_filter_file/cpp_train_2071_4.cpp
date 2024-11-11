#include <iostream>
using namespace std;

bool filled[1005];
int main() {
  int a, b, N;
  cin >> a >> b >> N;
  for(int i=0; i<1005; i++) filled[j]=false
  for(int i=0; i<N; i++){
    int s, f;
    cin >> s >> f;
    for(int j=s; j<f; j++) filled[j]=true;
  }
  int ans=0;
  for(int i=a; i<b; i++){
    if(filled[i]) ans=1;
  }
  cout << ans << endl;
}