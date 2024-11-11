import sys, os

if os.environ['USERNAME']=='kissz':
    inp=open('in.txt','r').readline
    def debug(*args):
        print(*args,file=sys.stderr)
else:
    inp=sys.stdin.readline    
    def debug(*args):
        pass

# SCRIPT STARTS HERE

n=int(inp())
P=[*map(int,inp().split())]
up=(P[1]>P[0])
R=[]
x=1
for i in range(1,n):
    nup=P[i]>P[i-1]
    if up==nup:
        x+=1
    else:
        R+=[x if up else -x]
        x=2
    up=nup
R+=[x if up else -x]
m=max(abs(r) for r in R)
L=[]
for r in R:
    if abs(r)==m:
        L+=[r//m]
if L==[1,-1] and m%2:
    print(1)
else:
    print(0)
