n=int(input())
l=list(map(int,input().split()))
x=l.index(max(l))
y=l.index(min(l))
l.reverse()
z=l.index(min(l))
if x>y and len(l)-z<=x:
    print(x+z-1)
else:
    print(x+z)