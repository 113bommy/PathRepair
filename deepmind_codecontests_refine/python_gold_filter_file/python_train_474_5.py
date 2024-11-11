def kamni(lst, k):
    count1 = 0
    for i in range(len(lst)):
        count1 += lst[i] // k
        if lst[i] % k != 0:
            count1 += 1
    count2 = count1 // 2
    if count1 % 2 != 0:
        count2 += 1
    return count2


n, K = [int(i) for i in input().split()]
b = [int(j) for j in input().split()]
print(kamni(b, K))
