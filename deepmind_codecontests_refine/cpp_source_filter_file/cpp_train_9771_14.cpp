include<iostream>
int main(){
  char c;
  std::cin>>c;
  std::cout<<(c^97&&c^101&&c^105&&c^111&&c^117?"consonant":"vowel");
}