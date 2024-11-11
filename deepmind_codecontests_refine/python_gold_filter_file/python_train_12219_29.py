import sys
inp=sys.stdin.readline
out=sys.stdout.write
def ii(): return int(inp())
def mi(): return map(int,inp().strip().split())
def li(): return list(map(int,inp().strip().split()))
n=ii()
l=li()
c1=0
c2=0
c3=0
for i in range(n):
    if (i+1)%3==1:
        c1+=(l[i])
    elif (i+1)%3==2:
        c2+=(l[i])
    else:
        c3+=(l[i])
#print(c1,c2,c3)
m=max(c1,c2,c3)
#print(m)
if c1==m:
    print("chest")
elif c2==m:
    print("biceps")
else:
    print("back")