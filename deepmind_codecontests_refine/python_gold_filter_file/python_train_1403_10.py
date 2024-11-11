n , k = map(int,input().split())
arr = list(map(int,input().split()))
arr = [[i,j] for i,j in enumerate(arr)]
#print(arr)
arr = sorted(arr,key = lambda x:x[1])
#print(arr)
out = []
for i in range(n):
    if arr[i][1]<=k:
        k -= arr[i][1]
        out.append(arr[i][0]+1)
    else:
        break
print(len(out))
print(*out)