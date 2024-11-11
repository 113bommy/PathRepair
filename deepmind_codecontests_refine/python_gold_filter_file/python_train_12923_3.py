import sys
import math
from collections import defaultdict,deque
import heapq
n,b=map(int,sys.stdin.readline().split())
primes=defaultdict(int)
newb=b
for i in range(2,int(math.sqrt(b))+1):
	if(b%i)==0:
		while b%i==0:
			primes[i]+=1
			b//=i
if b!=1:
	primes[b]+=1
mp=defaultdict(int)
ans=1e40
#print(primes)
for i in primes:
	num=n
	pr=i
	rem=i
	while pr<=num:
		mp[rem]+=num//pr
		pr*=rem
	#print(mp[rem])
	y=mp[rem]//primes[i]
	#print(y,'y')
	ans=min(ans,y)
print(ans)