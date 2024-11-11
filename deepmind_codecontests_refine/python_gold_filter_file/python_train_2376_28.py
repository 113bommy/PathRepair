h,w = map(int,input().split())
l = [list(map(int,input().split())) for i in range(h)]
count = 0
ans =[]
for i in range(h):
    for j in range(w-1):
        if l[i][j] %2 == 1:
            l[i][j+1] += 1
            ans.append([i+1,j+1,i+1,j+2])
            count += 1
for i in range(h-1):
    if l[i][w-1] %2 == 1:
        count += 1
        l[i+1][w-1] += 1
        ans.append([i+1,w,i+2,w])
print(count)
for i in ans:
    print(*i)