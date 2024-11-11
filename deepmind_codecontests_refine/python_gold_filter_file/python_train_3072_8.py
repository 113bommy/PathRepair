
n = int(input())
x1, x2 = [int(x) for x in input().split(' ')]

YSSorted = []
for i in range(n):
    k, b = [int(x) for x in input().split(' ')] 
    y1 = k*x1 + b
    y2 = k*x2 + b
    YSSorted.append((y1, y2))

YSSorted.sort(reverse=True)

def solve(YSSorted):
    minY2 = YSSorted[0][1]
    for y1, y2 in YSSorted:
        if y2 > minY2:
            return 'Yes'
        minY2 = min(minY2, y2)
    return 'No'

print(solve(YSSorted))
