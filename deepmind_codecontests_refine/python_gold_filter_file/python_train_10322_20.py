n = int(input())
L = [ int(i) for i in input().split() ]


for i in range (n-1,0,-1) :
	if L[i] != L[i-1] :
		print(i)
		break 