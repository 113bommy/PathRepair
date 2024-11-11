n,m = list(map(int,input().split()))
arr = list(map(int,input().split()))
arr.sort()
temp = []
ans = [False]*(2*(10**5))
for i in range(n):
    if arr[i]>=len(ans):
        pass
    else:
        ans[arr[i]] = True
for i in range(1,len(ans)):
    if ans[i]==False:
        m-=i
        if m>=0:
            temp.append(i)
        else:
            break
print(len(temp))
print(*temp)
