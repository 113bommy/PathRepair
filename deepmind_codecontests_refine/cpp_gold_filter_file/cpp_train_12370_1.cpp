#include<iostream>
#include<string>

int main(){
	int n;
	std::cin>>n;

	std::string str;

	if (n == 0) {
		std::cout << "0" << std::endl;
		exit(0);
	}

	while (n!=0) {
		if (n % 2 == 0) {
			str ="0"+str;
		}
		else {
			str = "1"+str;
			n--;
		}

		n/=-2;
	}

	std::cout<<str<<std::endl;
	return 0;
}