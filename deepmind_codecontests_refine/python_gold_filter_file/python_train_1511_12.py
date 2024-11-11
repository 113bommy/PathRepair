n=int(input())
a=list(map(int, input().split()))
di=[0]*(10**6+699)
for i in a:
    di[i]+=1

ans=0
for i in range(10**6+698): 
    di[i], di[i+1] = di[i] % 2, di[i+1] + di[i] // 2
    if di[i] % 2 == 1: ans += 1

#print(di[:3])
print(ans)