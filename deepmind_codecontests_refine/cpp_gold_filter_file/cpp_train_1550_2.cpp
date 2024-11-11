#include<iostream>

int main()
{
	char abacus[8][5];
	
	bool first=true;
	while(1)
	{
		int num;
		std::cin>>num;
		if(std::cin.eof())break;
		
		for(int c=4;c>=0;c--)
		{
			int digit=num%10;
			num/=10;
			int q=digit/5;
			int s=digit%5;
			int i=0;
			if(q==1)
			{
				abacus[0][c]=' ';
				abacus[1][c]='*';
			}
			else
			{
				abacus[0][c]='*';
				abacus[1][c]=' ';
			}
			abacus[2][c]='=';
			
			for(i=3;i<3+s;i++)
			{
				abacus[i][c]='*';
			}
			abacus[i++][c]=' ';
			for(;i<8;i++)
			{
				abacus[i][c]='*';
			}
		}
		if(first){first=false;}
		else{std::cout<<std::endl;}
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<5;j++)
			{
				std::cout<<abacus[i][j];
			}
			std::cout<<std::endl;
		}
	}
	return 0;
}