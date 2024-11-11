arr = list(map(int, input().split()))
summ = 0
for i in range(14):
    copy = [0] * 14
    now = arr[i]
    for j in range(14):
        copy[j] = arr[j]
    copy[i] = 0    
    for k in range(i + 1, 14):
        if now <= 0:
            break
        copy[k] += 1
        now -= 1
    s = now // 14
    for k in range(14):
        copy[k] += s
    for k in range(now % 14):
        copy[k] += 1
    local_s = 0
    for el in copy:
        if el > 0 and el % 2 == 0:
            local_s += el
    if local_s > summ:
        summ = local_s
print(summ)        