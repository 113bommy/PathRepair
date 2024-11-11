from collections import deque
N = int(input())
G = [[] for _ in range(N + 1)]
dist = [-1 for _ in range(N + 1)]
for _ in range(N - 1):
    a, b = map(int, input().split())
    G[a].append(b)
    G[b].append(a)
zero = []
one = []
two = []
for i in range(1, N + 1):
    if i % 3 == 1:
        one.append(i)
    elif i % 3 == 2:
        two.append(i)
    else:
        zero.append(i)
q = deque([1])
dist[1] = 0

while q.__len__() != 0:
    s = q.popleft()
    for i in G[s]:
        if dist[i] == -1:
            q.append(i)
            dist[i] = (dist[s] + 1) % 2

red = 0
blue = 0

for i in range(1, N + 1):
    if dist[i] == 0:
        red += 1
    else:
        blue += 1
ans = []
if red > N / 3 and blue > N / 3:
    for i in range(1, N + 1):
        if dist[i] == 0 and one.__len__() != 0:
            ans.append(one.pop())
        elif dist[i] == 1 and two.__len__() != 0:
            ans.append(two.pop())
        else:
            ans.append(zero.pop())
elif red <= N / 3:
    for i in range(1, N + 1):
        if dist[i] == 0:
            ans.append(zero.pop())
        else:
            if one.__len__() != 0:
                ans.append(one.pop())
            elif two.__len__() != 0:
                ans.append(two.pop())
            else:
                ans.append(zero.pop())

else:
    for i in range(1, N + 1):
        if dist[i] == 1:
            ans.append(zero.pop())
        else:
            if one.__len__() != 0:
                ans.append(one.pop())
            elif two.__len__() != 0:
                ans.append(two.pop())
            else:
                ans.append(zero.pop())

print(*ans)
