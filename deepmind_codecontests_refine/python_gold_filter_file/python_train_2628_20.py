import sys
def eprint(*args):
    print(*args, file=sys.stderr)
zz=1
if zz:
	input=sys.stdin.readline
else:	
	sys.stdin=open('input.txt', 'r')
	sys.stdout=open('all.txt','w')

t=int(input())
while t>0:
	t-=1
	n,m=map(int,input().split())
	if n*m>4 and min(n,m)>1:
		print("NO")
	else:
		print("YES")	