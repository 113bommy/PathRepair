def getCost(a, k):
    b = a.copy()
    for i in range(0, len(a)):
        b[i] += k * (i+1)
    b.sort()
    cost = 0
    for i in range(0,int(k)):
        cost += b[i]
    return cost

n, s = list(map(int,input().split()))
a = list(map(int,input().split()))

left = 0
right = n
num = 0
spent = 0
while(left <= right):
    mid = int(left + right)//2
    cost = getCost(a, mid)
    if cost <= s:
        left = mid + 1
        num = mid
        spent = cost
    else:
        right = mid - 1
print(num, " ", spent)