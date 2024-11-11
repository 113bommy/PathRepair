n,m=map(int, input().split())
ab=[list(map(int, input().split())) for _ in range(m)] 

ab.sort(key=lambda ab:ab[1])
ans=[ab[0]]
for i in range(1,m):
    if ans[-1][1]<=ab[i][0]:
        ans.append(ab[i])
print(len(ans))