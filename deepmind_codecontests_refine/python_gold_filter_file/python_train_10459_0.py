a, b = map(int, input().split())
if a == b:
    print('infinity')
elif a < b:
    print(0)
else:
    c = a - b
    s = [(c // i) for i in range(1, min(c, 40000)) if a % (c // i) == b] +\
        [i      for i in range(1, 40000) if a % i == b]
    s = set(s)
    print(len(s))
