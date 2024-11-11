from sys import stdin,stdout
stdin.readline
def mp(): return list(map(int, stdin.readline().strip().split()))
def it():return int(stdin.readline().strip())
from math import ceil
from collections import defaultdict as dd
from collections import Counter as C

n,x,y = mp()
l = list(input())
ans =0
# if l[n-x-1] !='1' and y >0:
# 	ans +=1
for i in range(n-x,n):
	# print(l[i])
	if l[i] == '1' and i != n-y-1:
		ans+=1
	elif l[i] == '0' and i == n-y-1:
		ans += 1
print(ans)

