n, m = list(map(int,input().split()))
a = [ input() for i in range(n)]
cnt = [0 for _ in range(m)]
for x in range(n):
    for k in range(m):
        if a[x][k] == '1':
            cnt[k]+=1
t = True
for x in range(n):
    t = True
    for k in range(m):
        if a[x][k]=='1' and cnt[k]==1:
            t = False
    if t:
        print('YES')
        exit()
print('NO')