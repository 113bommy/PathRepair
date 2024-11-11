import sys,math
from collections import deque,defaultdict
import operator as op
from functools import reduce
from itertools import permutations
import heapq

#sys.setrecursionlimit(10**7) 
# OneDrive\Documents\codeforces

I=sys.stdin.readline

alpha="abcdefghijklmnopqrstuvwxyz"

mod=10**9 + 7

"""
x_move=[-1,0,1,0,-1,1,1,-1]
y_move=[0,1,0,-1,1,1,-1,-1]
"""
def ii():
	return int(I().strip())
def li():
	return list(map(int,I().strip().split()))
def mi():
	return map(int,I().strip().split())


def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer // denom 



def isPrime(n):
	if n<=1:
		return False
	elif n<=2:
		return True
	else:
		
		for i in range(2,int(n**.5)+1):
			if n%i==0:
				return False
		return True




def main():
	s=I().strip()
	ans=[]

	for i in s:
		if len(ans)>1:
			if i!=ans[-1] or i!=ans[-2]:
				ans.append(i) 
		else:
			ans.append(i)

	for i in range(len(ans)):
		if i>2:
			if (ans[i-3]==ans[i-2]) and (ans[i-1]==ans[i]):
				ans[i]="$"
	tmp=""
	
	for i in ans:
		if i!="$":
			tmp+=i
	print(tmp)			


	





			

	

		

	













		

		


		





					

if __name__ == '__main__':
	main()