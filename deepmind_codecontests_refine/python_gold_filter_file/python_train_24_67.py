t=int(input())
for j in range(t):
    n=int(input())
    list1=list(map(int,input().split(" ")))
    a=0
    b=1
    ct=0
    for i in range(2,n):
        if list1[i]>=list1[a]+list1[b]:
            print(a+1,b+1,i+1)
            ct+=1
            break
    if not ct:
        print(-1)
    