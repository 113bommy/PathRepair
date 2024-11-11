
for t in range(int(input())):
    n, k = map(int, input().split())
    if n < k:
        print("NO")
        continue
    r = True
    y = (1 + (n-k))
    if y>0 and y % 2 == 1:
        print("YES")
        ans = [1]*(k-1) + [y]
        print(*ans)
        r = False
    if r:
        y = n - 2*(k-1)
        if y > 0 and y % 2 == 0:
            print("YES")
            ans = [2]*(k-1) + [y]
            print(*ans)
            r = False
    if r:
        print("NO")

    

