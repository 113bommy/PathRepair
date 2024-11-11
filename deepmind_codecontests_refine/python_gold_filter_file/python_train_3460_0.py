k = int(input().strip())

for _ in range(k):
    a, b, c, d = list(map(int, input().strip().split(" ")))
    print("%d %d %d" % (b, c, c))
