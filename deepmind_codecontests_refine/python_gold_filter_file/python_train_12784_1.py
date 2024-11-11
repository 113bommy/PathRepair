n, x = map(int, input().split())
l = list(map(int, input().split()))
print(1+sum(i <= x for i in [sum(l[0:i+1]) for i in range(n)]))