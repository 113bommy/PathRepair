n=int(input())
a=list(map(int,input().split()))
l=list(set(a))
l.sort()
if len(l) >=2:
    print(l[1])
else:
    print("NO")