n, k = map(int, input().split())

if k == 0:

    x = 1
    for _ in range(0,n):
        print(x,end=" ")
        x = x+1

elif k == n-1:

    x = n
    while x>0:
        print(x, end=" ")
        x = x - 1

else:

    rem = n-k-1
    start = 1

    for _ in range(0,rem):
        print(start, end=" ")
        start =  start + 1

    while k>=0:
        print(n,end=" ")
        n = n -1
        k = k -1

print("")

