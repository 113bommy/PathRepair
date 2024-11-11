n = int(input())
a = list(map(int, input().split()))
s = set()
cnt = 0
for i in a:
    if i >= 3200:
        cnt += 1
    else:
        s.add(i // 400)
print(max(1, len(s)), len(s) + cnt)