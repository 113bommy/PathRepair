n,c = map(int, input().split())

arr = list(map(int, input().split()))

ans = 1

for i,j in enumerate(arr):
    
    if i >= 1:
        
        if j - arr[i-1] > c:
            
            ans = 1
            
        else:
            
            ans += 1
            
print(ans)