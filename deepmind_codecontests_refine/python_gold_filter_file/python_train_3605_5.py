n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
b.sort()
if sum(a)<=b[-1]+b[-2]:
    print("YES")
else:
    print("NO")
