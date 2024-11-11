n, k = [int(x) for x in input().split(' ')]
d = set(x for x in input().split(' '))

for i in range(100000):
    if set(str(i)).isdisjoint(d) and i >= n:
        print(i)
        exit()