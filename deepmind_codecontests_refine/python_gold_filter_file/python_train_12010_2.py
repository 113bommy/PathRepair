n=int(input())
a=list(map(int,input().split()))
a=list(set(a))
a.sort()
if len(a)==1:
    print("NO")
else:
    print(a[1])