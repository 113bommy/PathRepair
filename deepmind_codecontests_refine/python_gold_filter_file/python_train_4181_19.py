# import sys
# sys.stdin=open("input.in","r")
# sys.stdout=open("output.out","w")
t=int(input())
for i in range(t):
	x=list(map(str,input()))
	s=''.join(sorted(x))
	y='abcdefghijklmnopqrstuvwxyz'
	if s in y:
		print("Yes")
	else:
		print("No")



