p, x, y, n, t = [], 0, 0, int(input()), list(map(int, input().split()))
for i in range(n):
    if t[i] < 0: x += 1
    if x == 3:
        p.append(i - y)
        x = 1
        y = i
    
p.append(n - y)
print(len(p))
print(' '.join(str(i) for i in p))