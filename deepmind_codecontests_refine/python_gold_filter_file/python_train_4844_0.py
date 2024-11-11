n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

i = 0
t = 0 if a[0] != 0 else 1
for j in range(n):
    if a[t] == b[j]:
        i = j
        break
bl = True
for j in range(n):
    if b[i % n] != a[j]:
        if a[j] == 0:
            continue
        elif b[i % n] == 0 and b[(i + 1) % n] == a[j]:
            i += 2
            continue
        bl = False
        break
    i += 1
print("YES" if bl else "NO")
