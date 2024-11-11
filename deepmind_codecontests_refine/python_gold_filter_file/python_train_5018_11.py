# import sys
# sys.stdin=open("input1.in","r")
# sys.stdout=open("outpul.out","w")
for _ in range(int(input())):
	a,b=map(int,input().split())
	if a>b:
		a,b=b,a
	diff=b-a
	ans=0
	ans+=diff//5
	diff=diff%5
	ans+=diff//2
	diff=diff%2
	ans+=diff
	print(ans)













