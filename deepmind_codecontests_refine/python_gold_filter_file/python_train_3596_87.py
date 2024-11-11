x = [int(x) for x in input().split()]
count = 0
for i in range(x[0]):
    s = [s for s in input().split()]
    if "+" in s:
        x[1] += int(s[1])
    elif '-' in s and x[1] >= int(s[1]):
        x[1] -= int(s[1])
    else:
        x[1] += 0
        count += 1
print(x[1], count)

