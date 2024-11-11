t=int(input())
while t:
    n=int(input())
    l=[int(x) for x in input().split()]
    for i in range(n-1,1,-1):
        if l[0]+l[1]<=l[i]:
            print(1,2,i+1)
            break
    else:
        print(-1)
    t-=1