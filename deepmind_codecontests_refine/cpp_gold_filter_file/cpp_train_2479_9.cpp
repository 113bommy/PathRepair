#include <iostream>
using namespace std;

int main(){
	int H,W,h,w,o;
	cin >> H >> W >> h >> w;
	o= h*W+H*w - h*w;
	cout << H*W-o;
}