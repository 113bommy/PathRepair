# May the Speedforce be with us...
'''
for _ in range(int(input())):
arr=list(map(int,input().split()))
n,k=map(int,input().split())
n=int(input())
s=input()

from collections import defaultdict
d=defaultdict()

d=dict()
s=set()
s.intersection()
s.union()
s.difference()


problem statement achhe se padhna hai
age se bhi dekhna hai, piche se bhi dekhna hai
'''
from math import gcd,ceil
from collections import defaultdict as dd
def lcm(a,b):
	return (a*b)//gcd(a,b)
def inin():
	return int(input())
def inar():
	return list(map(int,input().split()))
def ar(element,size):
	return [element for i in range(size)]
def digitsum(num):
	su=0
	while(num):
		su+=num%10
		num//=10
	return su

ss=set()
for k in range(1,11):
	num='1'*k+'0'*(k-1)
	ss.add(int(num,2))
n=inin()
i=1
ans=1
while(i*i<=n):
	if n%i==0:
		div1=i
		div2=n//i
		if div1 in ss:
			ans=max(ans,div1)
		if div2 in ss:
			ans=max(ans,div2)
	i+=1
print(ans)