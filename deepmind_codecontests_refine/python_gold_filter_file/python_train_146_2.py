t=int(input())
a=list(map(int,input().split()))
if ((sum(a)/100)%2==1) or (min(a)==200 and sum(a)%400!=0):
    print("NO")
else:
    print("YES")