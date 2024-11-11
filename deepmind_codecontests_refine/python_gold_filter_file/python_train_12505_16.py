x=int(input())
p=0
for a in range(x,0,-1):
    for b in range(1,a+1):
        if a%b==0 and a*b>x and a/b<x:
            print(str(a)+' '+str(b))
            p=1
            break
    if p==1:
        break
if p==0:
    print(-1)
