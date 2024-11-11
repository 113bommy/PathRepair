m,b = map(int, input().split())

def bananas(a,b):
    return a*(a + 1) // 2 * (b + 1) + (a + 1) * (b * (b + 1) // 2)

currentMax = 0
for i in range(0,b*m + 1,m):
    currentMax = max(currentMax, bananas(i, -i//m + b))
print(currentMax)