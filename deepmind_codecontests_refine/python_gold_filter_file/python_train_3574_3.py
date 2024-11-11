# Problem: C. Median
# Contest: Codeforces - Codeforces Round #113 (Div. 2)
# URL: https://codeforces.com/problemset/problem/166/C
# Memory Limit: 256 MB
# Time Limit: 2000 ms
# 
# KAPOOR'S

from sys import stdin, stdout 

def INI():
	return int(stdin.readline())
	
def INL():
	return [int(_) for _ in stdin.readline().split()]
	
def INS():
	return stdin.readline()

def MOD():
    return pow(10,9)+7
	
def OPS(ans):
	stdout.write(str(ans)+"\n")
	
def OPL(ans):
	[stdout.write(str(_)+" ") for _ in ans]
	stdout.write("\n")

from bisect import bisect_left	
if __name__=="__main__":
	n,x=INL()
	X=sorted(INL())
	
	m=(n-1)//2
	
	ans=0
	
	if X[m]<x:
		for _ in range(m,n):
			if X[_]>=x:
				i=_
				break
		else:
			i=n
		ans+=2*(i-m)
		if n%2==0:
			ans-=1
		
	elif x<X[m]:
		for _ in range(m,-1,-1):
			if X[_]<=x:
				i=_
				break
		else:
			i=-1
		ans+=2*(m-i)
		if n%2==1:
			ans-=1
	OPS(ans)