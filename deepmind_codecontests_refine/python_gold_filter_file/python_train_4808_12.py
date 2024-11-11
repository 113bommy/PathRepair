n = int(input())
a = list(map(int, input().split()))
a += a
ans = n
 
for i in range(n):
    s = set()
    
    for j in range(i, i+n):
        if a[j] not in s:
            s.add(a[j])
            
            if i==0 or j>=n-1:
                ans = min(ans, n-(j-i+1))
        else:
            break
 
print(ans)