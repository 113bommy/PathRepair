t= int(input())
for i in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    a=l[0]
    sum=0
    for j in l:
        if (a//j<0):
            sum+=a
            a=j
        elif a<j:
            a=j
        else:
            continue
    print(sum+a)