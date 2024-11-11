n = int(input())
arr = list(map(int, input().split()))
i = 0
cm = 1
while i < n:
    cc = 1
    curr = arr[i]
    j = i-1
    k = i+1
    while j >= 0:
        if curr >= arr[j]:
            cc += 1
        else:
            break
        curr = arr[j]
        j -= 1
    curr = arr[i]
    while k < n:
        if curr >= arr[k]:
            cc += 1
        else:
            break
        curr = arr[k]
        k += 1
    i += 1
    if cc > cm:
        cm = cc

print(cm)
