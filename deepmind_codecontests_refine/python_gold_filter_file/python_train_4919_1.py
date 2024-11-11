ar = []
for j in input().split(' '):
    ar.append(int(j))
if ar[1]/ar[0]>=2:
    print('YES')
    res = [1]*ar[0]
    res[-1] = res[-1] + ar[1] - sum(res)
    print(*res)
    print(ar[1]//2)
else:
    print('NO')
