n = int(input())

data = []

for _ in range(n):
    data.append([int(x) for x in input().split(' ')])

k = int(input())

for i, (l, r) in enumerate(data):
    # print(i, l, r)
    if k >= l and k <= r:
        print(n - i)