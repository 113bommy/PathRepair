# import sys
# sys.stdin=open("input.in",'r')
# sys.stdout=open("ou.out",'w')
n=int(input())
for i in range(n):
	s=list(input())
	s.sort()
	if s[0]==s[-1]:
		print(-1)
	else:
		print("".join(s))