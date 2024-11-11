from bisect import bisect_left,bisect
n = int(input())
b = list(map(int,input().split()))
s =0
t=[]
for i in b:
	s+=i
	t.append(s)
input()
for j in map(int,input().split()):
	print(bisect_left(t,j)+1)