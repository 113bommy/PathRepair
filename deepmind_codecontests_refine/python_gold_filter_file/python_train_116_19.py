n = int(input())
a = input()
ans = []
for i in range(n-1):
    if a[i]>a[i+1]:
        ans = [i+1,i+2]
        break
if len(ans)>0:
    print('YES')
    print(*ans)
else:
    print('NO')