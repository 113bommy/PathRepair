#include<cassert>
using namespace std;

int main() {
  int H, A, B; cin >> H >> A >> B;

  int cnt = 0;
  for ( int i = A; i <= B; i++ ){
    cnt += (H % i == 0 );
  }

  cout << cnt << endl;
}
