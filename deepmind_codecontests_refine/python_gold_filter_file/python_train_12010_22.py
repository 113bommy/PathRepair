n=int(input())
a=list(map(int, input().split()))
l=list(set(a))
l.sort()
if len(l)==1:
    print("NO")
else:
    print(l[1])
