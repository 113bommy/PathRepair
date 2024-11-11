n, x = list(map(int,input().split()))
if n == 1:
    print("YES")
    print(x)
elif n == 2 and x == 0:
    print("NO")
elif n == 2 and x != 0:
    print("YES")
    print(0, x)
else:
    print("YES")
    a = 131072
    b = 131072*2
    ans = 0
    for i in range(1, n-2):
        ans = ans^i
        print(i, end = ' ')
    if x == ans:
        print(a, b, a^b)
    else:
        print(ans^a^b^x, a, b)
    
