n, v = map(int, input().split())

if n-1 <= v:
    print(n-1)
else:
    res = v
    for i in range(2, n-v+1):
        res += i
    print(res)