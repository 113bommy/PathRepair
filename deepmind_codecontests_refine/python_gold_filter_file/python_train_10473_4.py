# Time   : 2017-6-26 13:30
# Auther : Anjone
# URL : http://codeforces.com/contest/821/problem/B

from math import floor;
getsum = lambda x,y : int((int(y)+1) * (int(x)+int(y)) * (int(x)+1) // 2)  

m,b = map(int,input().split())
ans = 0
for i in range(b+1):
	x = (b-i)*m
	ans = max(ans, getsum(x,i))
print(ans)