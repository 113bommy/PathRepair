z=int(input())
x=list(map(int,input().split()))
a=max(x)-1
for i in range(100):
    energy=0
    a+=1
    t=True
    x=[a]+x
    for o in range(z-1):
        energy=energy+(x[o]-x[o+1])
        if energy<0:
           
            t=False
            break
    if t:
        print(a)
        break