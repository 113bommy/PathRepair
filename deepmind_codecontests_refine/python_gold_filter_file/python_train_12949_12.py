n = int(input())
l = list(map(int, input().split()))
mini = min(l)
f = 1
for i in l:
    if i % mini != 0:
        f = 0
        break
print(mini if f == 1 else -1)
