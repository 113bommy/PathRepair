X,Y,Z,K=map(int,input().split())
A=list(map(int, input().split()))
B=list(map(int, input().split()))
C=list(map(int, input().split()))
AB=[]
for a in A:
	for b in B:
		AB.append(a+b)
ABC=[]
for ab in sorted(AB, reverse=True)[:K]:
	for c in C:
		ABC.append(ab+c)
for abc in sorted(ABC, reverse=True)[:K]:
	print(abc)
