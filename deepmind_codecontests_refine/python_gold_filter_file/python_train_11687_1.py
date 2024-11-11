import sys
import math 
from decimal import *
def I(): return int(sys.stdin.readline())
def IL(): return list(map(int,sys.stdin.readline().strip().split()))
def ILS(): return list(map(str,sys.stdin.readline().strip().split()))






def solve():
	tt = I()
	for ii in range(tt):
		n,k,l = IL()
		d = IL()
		tmp = []
		kl = []
		for i in range(k+1):
			tmp.append(0);
		for i in range(k-1,0,-1):
			tmp.append(0)
		dp = [tmp.copy() for dd in d]
		# print(dp)
		for i in range(k+1):
			kl.append(i);
		for i in range(k-1,0,-1):
			kl.append(i)

		for i in range(len(tmp)):
			if d[0] + kl[i] <= l : dp[0][i] = 1
			else : dp[0][i] = 0
		for i in range(1,len(d)):
			for j in range(len(dp[i])):
				k = j-1
				if k <0 : k = len(dp[i])-1
				if d[i]+kl[j] <= l : 
					dp[i][j] = 1 if dp[i-1][k]+dp[i][k] > 0 else 0
				else : dp[i][j] = 0
				
		# print(dp)
		# for pp in dp :
		# 	print(pp)
		flag = 0
		for i in range(len(dp[-1])):
			if dp[-1][i] == 1 : flag = 1; break;
		if flag == 1 : print("Yes")
		else : print("No")
		# cal(d,-1)
		pass

solve()