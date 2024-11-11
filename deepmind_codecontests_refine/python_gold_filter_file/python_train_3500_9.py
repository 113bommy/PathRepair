n, m = map(int, input().split())
x = [int(a) for a in input().split()]
if m == 1:
    print(min(x))
elif m == 2:
    print(max(x[0],x[n-1]))
else:
    print(max(x))
    