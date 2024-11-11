n , m = map(int, input().split())
l = [list(map(int,input().split())) for _ in range(m)]
l.sort()
l = l[::-1]
cnt = 1
key = l[0][0]
for i in range(1,m):
    if key >= l[i][1]:
        cnt += 1
        key = l[i][0]
print(cnt)
    
