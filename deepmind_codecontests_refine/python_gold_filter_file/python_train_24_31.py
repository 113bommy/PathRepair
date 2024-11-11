t=int(input())
while(t>0):
    n=int(input())
    l=list(map(int,input().split()))
    s=l[0]+l[1]
    for i in range(2,n):
        if l[i]>=s:
            print(1,2,i+1)
            break
    else:
        print(-1)
    t-=1
