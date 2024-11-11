import time
t = time.time()
n = int(input())
a = list(map(int, input().split()))
d = {}
for i in range(n):
    for j in range(i+1, n):
        x = a[i] + a[j]
        if d.get(x, set()) & {i+1, j+1} == set():
            d[x] = d.get(x, set()) | {i+1, j+1}
        if len(d.get(x, set())) == 4:
            print("YES")
            print(*d[x])
            exit()
        #if time.time() - t > 0.95:
        #    break
print("NO")