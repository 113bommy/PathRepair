import sys
import collections as cc

I = lambda : list(map(int,input().split()))
mod = 10**9+7
def ch(temp):
	tans = 0
	for i in range(len(temp)-k-1,-1,-k):
		tans += 2*abs(temp[i])
	return tans 

for tc in range(int(input())):
	s = input()
	t = input()
	ar = [s.count('a'),s.count('b'),s.count('c')]
	new = [i for i in s if i not in ['a','b','c']]
	new.sort()
	#print(ar)
	if t!='abc' or (ar[0]==0 or ar[1]==0 or ar[2]==0):
		print('a'*ar[0]+'b'*ar[1]+'c'*ar[2]+''.join(new))
	else:
		print('a'*ar[0]+'c'*ar[2]+'b'*ar[1]+''.join(new))


