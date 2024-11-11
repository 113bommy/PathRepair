#include<iostram>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int ans=b/a<c? b/a:c;
  cout<<ans;
  return 0;
}