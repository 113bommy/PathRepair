from sys import stdin,stdout
from collections import defaultdict,Counter,deque
from bisect import bisect,bisect_left
import math
from itertools import permutations 
import queue

#stdin = open('input.txt','r')
I = stdin.readline


def primeFactors(n):
	arr = defaultdict(lambda : 0)
	while(n%2==0):
		arr[2]+=1
		n = n // 2
	for i in range(3,int(math.sqrt(n))+1,2):
		while n % i== 0:
			arr[int(i)]+=1
			n = n/i
	if n > 2:
		arr[n]+=1
	return arr

        
    
            

            

    
          





def zero(n,x,power):


	
	zeros=0
	base = x
	while(n>=base):
		zeros+=(n//base)
		n//=base

	return (int(zeros//power))

n,b = map(int,I().split())

arr = primeFactors(b)
#print(arr)


mp = math.inf

for i in arr:
	now = zero(n,i,arr[i])
	if(now<mp):
		mp=now

print(mp)
