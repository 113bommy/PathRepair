MAX = 1000001

e = int(input())
q = input().split()
m = int(input())
arr1 = [MAX]*e

for i in range(m):
    [a, b, c] = list(map(int, input().split()))
    arr1[b-1] = min(arr1[b-1], c)

count = 0
for x in arr1:
    if x == MAX:
        count += 1
if count > 1:
    print(-1)
else:
    res = 0
    for k in arr1:
        if k != MAX:
            res += k
    print(res)
