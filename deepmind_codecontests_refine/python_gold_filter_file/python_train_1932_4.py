from collections import deque
n, q = map(int, input().split())
qu = deque()
first = [0]*(n+1)
second = [0]*(n+1)
total = 0
time = 0
ans = ''
for _ in range(q):
    t, x = map(int, input().split())
    if t == 1:
        first[x] += 1
        second[x] += 1
        total += 1
        qu.append(x)
    elif t == 2:
        total -= first[x]
        first[x] = 0
    else:
        while time < x:
            time += 1
            y = qu.popleft()
            second[y] -= 1
            if second[y] < first[y]:
                first[y] -= 1
                total -= 1
    ans += str(total)+'\n'
print(ans)
