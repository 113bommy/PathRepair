
n = int(input())

data = [int(x) for x in input().strip().split(" ")]

k = max(data)

x1 = sum(data)

x2 = sum([k - data[i] for i in range(n)])

while x2 <= x1:
    k += 1
    x2 = sum([k - data[i] for i in range(n)])


print(k)
