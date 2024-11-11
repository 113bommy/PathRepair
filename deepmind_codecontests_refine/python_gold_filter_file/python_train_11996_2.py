def solve(n, m):
    if m > arr[n]:
        return False, -1

    ind = None
    for i in range(1, 5001):
        if arr[i] <= m and m <= arr[i+1]:
            ind = i
            break
        
    ans = [i for i in range(1, ind+1)]
    
    if m > arr[ind]:
        ans.append(ans[-(m-arr[ind])*2]+ans[-1])
    
    cur  = 100000
    step = ans[-1] + 1 
    while len(ans) < n:
        ans.append(cur)
        cur+=step
        
    return True, ans    

arr  = [0]
for i in range(1, 5003):
    arr.append(arr[-1] + (i-1) // 2)
    
n, m = map(int, input().split())     
flg, ans = solve(n, m)

if flg==False:
    print(-1)
else:
    print(' '.join([str(x) for x in ans]))    