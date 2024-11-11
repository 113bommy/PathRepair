weight = list(input().split())
x = int(weight[0])
y = int(weight[1])
years = 0
while x < y or x == y:
    x *= 3
    y *= 2
    years += 1
print(years)