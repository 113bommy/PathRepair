import sys
input=sys.stdin.readline
for _ in range(int(input().strip())):
	#y,a,b=map(int,input().strip().split(" "))
	n=int(input().strip())
	s=input().strip()
	s1=input().strip()

	
	#a=list(map(int,input().strip().split(" ")))
	for i,j in zip(s,s1):
		if i==j=="1":
			print("NO")
			break
	else:
		print("YES")

	
