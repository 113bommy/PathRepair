t=int(input())
for i in range(t):
    a,b,c,d,k=map(int,input().split())
    s=0
    if a==c:
        j=0
    else:
        for j in range(k):
            if c*j<a<=c*(j+1):
                break
    if b==d:
        e=0
    else:
        for e in range(k):
            if d*e<b<=d*(e+1):
                break
    if j+e+2>k:
        print('-1')
    else:
        print(j+1,e+1)