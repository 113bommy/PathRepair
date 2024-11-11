n,m = map(int,input().split())
l = []
for i in range(m):
    l.append(list(map(int,input().split())))
ans = max(l[0][1]+l[0][0]-1,l[-1][1]+n-l[-1][0])
for i in range(m-1):
    if abs(l[i][1]-l[i+1][1]) > abs(l[i][0]-l[i+1][0]):
        ans = 'IMPOSSIBLE'
        break
    if l[i][1] > l[i+1][1]:
        ans = max(ans,l[i][1]+((l[i+1][0]-l[i][0])-(l[i][1]-l[i+1][1]))//2)
    else:
        ans = max(ans,l[i+1][1]+((l[i+1][0]-l[i][0])-(l[i+1][1]-l[i][1]))//2)
print(ans)
