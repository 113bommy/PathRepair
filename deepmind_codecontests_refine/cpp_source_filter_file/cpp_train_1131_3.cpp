#include <iostream>
#include <string>

int main(){
	int n; // the number of datasets
	std::cin >> n;
	std::cin.ignore();

	for(int i = 0; i < n; ++i){
		std::string text;
		std::getline(std::cin, text); // input
		
		int text_size = text.size();
		int moji = text.find("Hoshino");
		while(moji != basic_string::npos){
			text.replace(moji, 7, "Hoshina");
			moji = text.find("Hoshino", moji);
		}
		
		std::cout << text << std::endl; //output
	}

	return 0;
}