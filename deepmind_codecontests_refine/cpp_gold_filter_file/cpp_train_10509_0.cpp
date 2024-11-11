#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int T, card[16];

bool is_same_number(int a, int b, int c){
  return a == b && b == c;
}

bool is_sequence(int a, int b, int c){
  return a+2 == b+1 && b+1 == c;
}

bool is_good_set(int a, int b, int c){
  return is_same_number(a, b, c) || is_sequence(a, b, c);
}

bool is_all_good_set(){
  return (is_good_set(card[0], card[1], card[2]) && is_good_set(card[3], card[4], card[5]) && is_good_set(card[6], card[7], card[8]));
}

int win(){
  sort(card,card+9);
  do {
    if (is_all_good_set())
      return 1;
  } while(next_permutation(card, card+9));
  return 0;
}

int main(){

  cin >> T;
  for(int t=0; t<T; ++t){
    for(int i = 0; i < 9; ++i){
      cin >> card[i];
    }
    string color;
    for(int i = 0; i < 9; i++){
      cin >> color;
        if(color == "G") card[i] += 20;
        else if (color == "B") card[i] += 40;
    }

    cout << win() << endl;
  }

}
