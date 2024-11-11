a, b = map(int, input().split())
wir = 0

for k in map(int, input().split()):
    if b >= k:
        wir += 1
    elif b < k:
        wir += 2
print(wir)
    