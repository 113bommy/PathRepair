for i in range(int(input())):
	a=int(input())
	b=sorted(list(map(int,input().split())))
	r=1
	for j in range(a-1,-1,-1):
	    if b[j]<=j+1:
	        r=j+2
	        break
	print(r)