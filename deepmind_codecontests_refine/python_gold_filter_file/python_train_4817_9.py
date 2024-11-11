l=[]
for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    m=max(a)
    sum=0
    for i in range(n):
        sum=sum+a[i]
    if sum<2*m or sum%2==1:
        l.append("T")
    else:
        l.append("HL")
for i in l:
    print(i)
