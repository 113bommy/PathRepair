n,x=map(int, input().split())
sad=0
for i in range(n):
    z,amo=input().split()
    amo=int(amo)
    if z=='+':
        x+=amo
    elif x>=amo:
        x-=amo
    else:
        sad+=1
print(x,sad)
