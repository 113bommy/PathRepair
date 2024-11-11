n, m = map(int, input().split(' '))
a = [0]*m
b = [0]*m
for i in range(m):
    a[i], b[i] = list(map(int, input().split(' ')))

c = [-1]*(m+2)

def find(num):
    if c[num] < 0:
        return num
    else:
        k = find(c[num])
        c[num] = k
        return k

result = [int(n*(n-1)/2)]
for i in range(m-1, 0,-1):
    x = find(a[i])
    y = find(b[i])

    if x != y:
        result.append(result[-1]-c[x]*c[y])
        x, y = sorted([x,y])
        c[x] += c[y]
        c[y] = x
    else:
        result.append(result[-1])

for i in result[::-1]:
    print(int(i))
