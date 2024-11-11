N,M = tuple(int(i) for i in input().split())
A = list(int(i) for i in input().split())
AOE = 0
out = ""
for m in range(M):
	val = tuple(int(i) for i in input().split())
	if(val[0]==1):
		ind = val[1]
		x = val[2]
		A[ind-1]=x-AOE
	elif(val[0]==2):
		AOE += val[1]
	elif(val[0]==3):
		out += str(A[val[1]-1]+AOE) + "\n"
print(out,end="")
