n, k = map(int, input().split())
a = list(map(int, input().split()))
mn = min(a)
for i in a:
    if (i - mn) % k != 0:
        exit(print("-1"))
else:
    print(sum([(i - mn) // k for i in a]))
