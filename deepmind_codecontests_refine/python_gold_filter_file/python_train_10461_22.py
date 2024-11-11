import sys

t=sys.stdin.readline()
l=[]
 
while t :
    a=t.split()
    k=int(a[0])
    m=int(a[1])
    w=int(a[2])
    cost = int(k*(w+1)*w/2)
    if m > cost:
        print(0)
    else:
        print(cost-m)
    l=[] #empty list for next input ie (0 1 2).
    t=sys.stdin.readline()