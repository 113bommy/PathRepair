t=int(input())
while t:
    n,k=map(int,input().split())
    a= list(map(int,input().split(' ')))
    c=0
    mind=a.index(min(a))
    for i in range(0,len(a)):
        if(i!=mind):
            c+=(k-a[i])//min(a)
        else:
            continue
    print(c)
    c=0
    t-=1

        
