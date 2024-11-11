n = int(input())

data = list(map(int,input().split()))

data.sort()

min_sq = (data[-1] - data[n]) * (data[n -1] - data[0])

for i in range(1, n):
    if (data[-1] - data[0]) * (data[i + n - 1] - data[i]) < min_sq:
        min_sq = (data[-1] - data[0]) * (data[i + n - 1] - data[i])

print(min_sq)
