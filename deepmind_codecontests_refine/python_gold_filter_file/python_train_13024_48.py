n, s = [int(x) for x in input().split()]
if s>n:
    t = s//n
    if s%n: t+=1
    print(t)
else: print(s)