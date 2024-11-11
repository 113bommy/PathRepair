n = int(input())
a = list(map(int, input().split()))

a.sort(reverse=True)

cnt = 0
for i in range(1,n):
    cnt += a[i//2]

print(cnt)
