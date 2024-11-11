k, n, w = map(int, input().split())
c = w*(w+1)/2*k - n
if c <= 0:
    print(0)
else:
    print(int(c))