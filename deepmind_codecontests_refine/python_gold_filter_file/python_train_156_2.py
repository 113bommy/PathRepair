n, k = map(int, input().split(' '))
ids = input().split(' ')

t = int((k*2) ** 0.5)
while t * (t+1) // 2 < k:
    t += 1
print(ids[k - ((t-1)*t//2) - 1])
