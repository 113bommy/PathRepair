t=int(input())
for i in range(t):
    n,m=map(int,input().split(' '))
    ar=list(map(int,input().split(' ')))
    p=list(map(int,input().split(' ')))
    d=0
    for k in range(100):
        for j in range(n):
            if (j+1) in p and ar[j]>ar[j+1]:
                ar[j],ar[j+1]=ar[j+1],ar[j]
        if(ar==sorted(ar)):
            print("YES")
            d=1
            break
    if(d==0):
        print("NO")
            
