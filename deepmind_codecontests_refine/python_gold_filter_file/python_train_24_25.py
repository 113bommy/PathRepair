for _ in range(int(input())):
    n=int(input())
    l=[int(x) for x in input().split()]
    h=l[0]+l[1]
    count=0
    for i in range(2,n):
        if(l[i]>=h):
            count=1
            print("1 2",i+1)
            break
    if(count==0):
        print(-1)