def maxIncSubarr(a, n):  
    pre = [0] * n; 
    pos = [0] * n; 
    pre[0] = 1; 
    pos[n - 1] = 1; 
    l = 0;  
    for i in range(1, n): 
        if (a[i] > a[i - 1]): 
            pre[i] = pre[i - 1] + 1; 
        else: 
            pre[i] = 1; 
    l = 1; 
    for i in range(n - 2, -1, -1): 
        if (a[i] < a[i + 1]): 
            pos[i] = pos[i + 1] + 1; 
        else: 
            pos[i] = 1; 
    ans = 0; 
    l = 1; 
    for i in range(1, n): 
        if (a[i] > a[i - 1]): 
            l += 1; 
        else: 
            l = 1; 
        ans = max(ans, l);  
    for i in range(1, n - 1): 
        if (a[i - 1] < a[i + 1]): 
            ans = max(pre[i - 1] + pos[i + 1], ans); 
      
    return ans; 

n=int(input())
l=list(map(int,input().split()))
print(maxIncSubarr(l,n))