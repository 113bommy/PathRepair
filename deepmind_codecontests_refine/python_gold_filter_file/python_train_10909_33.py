N = int(input())
S = list(input())

ans = 0

for n in range(1000):
    pin = str(n).zfill(3)
    head = 0
    for c in S:
        if c == pin[head]:
            head += 1
        if head == 3:
            ans += 1
            break

print(ans)
