s, n = list(map(int, input().split()))

dragon_s = list()
bonus = list()
for i in range(n):
    ds, b = list(map(int, input().split()))
    dragon_s.append(ds)
    bonus.append(b)

for i in range(n):
    min_index = dragon_s.index(min(dragon_s))
    if s > dragon_s[min_index]:
        s = s + bonus[min_index]
        dragon_s.pop(min_index)
        bonus.pop(min_index)
    else:
        print("NO")
        exit()
print("YES")
