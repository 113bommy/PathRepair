


def bal_array(n) :

	if (n//2)%2 != 0 :
		print('NO')

	else :
		print('YES')
		
		for i in range (1,n//2 + 1) :
			print(i * 2, end = ' ')


		for i in range(1,n//2) : 

			print(i*2 -1,end = ' ')

		print( 3*n//2-1)
		

n = int(input())
for i in range(n) :
	testcase = int(input())
	bal_array(testcase)