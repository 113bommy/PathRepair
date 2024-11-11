'''
    Time complexity: O(N*(log(log(N)))
    Space complexity: O(N)
    where N is the input
'''


def solve(n) :

	isPrime = [True for i in range(n + 1)]
	primeCount = [0 for i in range(n + 1)]

	for i in range(2, n + 1) :

		if (isPrime[i] == True) :
			
			j = 2
			while(j * i <= n) :
					
				isPrime[i * j] = False
				primeCount[i * j] += 1
				j += 1

			
	ans = 0

	for i in range(1, n + 1) :
		
		if(primeCount[i] == 2) :
			
			ans += 1

	return ans


#main

n = int(input().strip())
print(solve(n))

