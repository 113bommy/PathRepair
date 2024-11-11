t = int(input())
k = 0
for i in range(t):
    a,b,c = map(int,input().split())
    while (c  > 1)and(b > 0):
        k += 3
        b -= 1
        c = c - 2
    while (b > 1)and(a > 0):
        k += 3
        b -= 2
        a -= 1
    print(k)
    k = 0