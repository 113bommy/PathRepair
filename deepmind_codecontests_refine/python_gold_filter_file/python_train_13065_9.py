n, m = map(int, input().split())
cnt = 0
for j in range(n):
    k = list(map(int, input().split()))
    for i in range(m):
        if k[2*i] == 1 or k[2*i+1] == 1:
            cnt+=1
print(cnt)
