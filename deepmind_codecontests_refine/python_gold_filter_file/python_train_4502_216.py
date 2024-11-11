t=int(input())
for x in range(t):
    n=int(input())
    if n&1==0:
        print((n//2)-1)
    else:
        print(n//2)