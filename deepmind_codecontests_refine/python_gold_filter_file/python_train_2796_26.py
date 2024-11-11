n,x = map(int,input().split())

# 仮説
if x in (1,2*n-1):
    print('No')
    exit()

res = [i for i in range(1,2*n)]

flag = False
if x > n:
    x = 2 * n - x
    flag = True

res = res[x-n:] + res[:x-n]

if flag:
    for i in range(2*n-1):
        res[i] = 2 * n - res[i]

print('Yes')
print(*res, sep='\n')
