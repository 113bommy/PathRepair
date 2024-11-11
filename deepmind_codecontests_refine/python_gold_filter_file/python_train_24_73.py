t = int(input())
for _ in range(0,t):
    n = int(input())
    a = [int(i) for i in input().split()]
    aa,bb,cc = a[0],a[1],a[-1]
    if aa+bb > cc and aa+cc > bb and bb+cc > aa:
        print(-1)
    else:
        print(1,2,n)