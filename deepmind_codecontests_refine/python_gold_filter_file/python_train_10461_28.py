k, n, w = list(map(int, input().split()))

res = (k*w*(1+w)) / 2 - n
print(int(res)) if res > 0 else print(0)