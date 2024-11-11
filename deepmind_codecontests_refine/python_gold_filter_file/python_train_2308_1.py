# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out","w")
l=list(map(int,input().split()))
a=l.pop()
l.sort()
c=0
for i in range(len(l)-1):
	if l[i+1]-l[i]<a:
		c+=abs(a-l[i+1]+l[i])
print(c)

