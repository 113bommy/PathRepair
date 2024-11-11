#include <iostream>
#include <string>

int base;

int hit(){
	if(base==3) return 1;
	else base++;
	return 0;
}

int homerun(){
	base++;
	return base;
}

int main(){
	int inning;
	std::cin >> inning;

	for(int i=0;i<inning;i++){
		int outCount=0;
		int point=0;
		std::string result;
		base=0;
		while(outCount<3){
			std::cin >> result;

			if(result == "HIT"){
				point += hit();
			} else if(result == "HOMERUN"){
				point += homerun();
				base=0;
			} else if(result == "OUT"){
				outCount++;
			}
		}
		std::cout << point << std::endl;
	}

    return 0;
}
