x=int(input())
a=list(map(int,input().split()))

b=list(set(a))
y=len(b)

print(x-(x-y)-(x-y)%2)
