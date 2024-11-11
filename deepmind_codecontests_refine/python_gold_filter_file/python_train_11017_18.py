N = int(input())
alist = [int(x) for x in input().split()]
positive =  max(alist)+min(alist) >=0
if positive:
	argmaxabs = alist.index(max(alist))
else:
	argmaxabs = alist.index(min(alist))
print(2*N-2)
for i in range(1,N+1):
	if not argmaxabs+1 == i:
		print(str(argmaxabs+1)+" "+str(i))
if positive:
	for i in range(1,N):
		print(str(i)+" "+str(i+1))
else:
	for i in range(N,1,-1):
		print(str(i)+" "+str(i-1))