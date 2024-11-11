n, b = map(int, input().split())
s = list(map(int, input().split()))
sb = sum(s) + b
sb /= n
if sb - max(s) >= 0:
    for x in s:
        print(sb-x)
else:
    print('-1')


