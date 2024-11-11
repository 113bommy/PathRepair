n = int(input())
li = list(map(int, input().split()))

se = set()
high = 0
for a in li:
    if a // 400 <= 7:
        se.add(a // 400)
    else:
        high += 1

print(max(1, len(se)), len(se) + high)
