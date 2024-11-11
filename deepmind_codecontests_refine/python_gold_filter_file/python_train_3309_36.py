S,T=input().split()
A,B=map(int,input().split())
X=input()
if S==X:
	print(A-1,B)
else:
	print(A,B-1)