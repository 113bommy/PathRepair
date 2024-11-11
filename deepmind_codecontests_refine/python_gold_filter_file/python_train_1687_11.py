n = int(input())
a = list(map(int, input().split()))

ids = []
for i in range(n):
    if a[i] == 1:
        ids.append(i)

m = len(ids)
sum = m

if sum == 1:
    print(-1)
    exit()

def calculate(inc):
    ret = 0
    for i in range(0,m,inc):
        mid = (i + (i + inc - 1)) // 2
        for j in range(i,i+inc):
            ret += abs(ids[j] - ids[mid])
    return ret

ans = 10 ** 18
div = 2
while div <= sum:
    if sum % div == 0:
        get = calculate(div)
        ans = min(ans, get)
    div += 1

ans = min(ans, calculate(m))

print(ans)