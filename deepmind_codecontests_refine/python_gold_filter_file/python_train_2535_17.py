n=int(input())
a=[i for i in range(1,n)]
if n>1:
    a=[n]+a
    print(*a)
else:
    print(1)
