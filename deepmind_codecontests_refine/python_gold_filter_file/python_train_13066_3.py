n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

l, r = 0, 0
hsh = [0] * 1000005
idx = [1, 1]
hsh[a[0]] = 1
cnt,ans = 1, -1

while(r < n - 1 and l <= r):
    if hsh[a[r + 1]] == 0 and cnt < k:#when incoming is unique and I can accomodate            
        r += 1
        hsh[a[r]] += 1
        cnt += 1
        if r - l > ans:
            idx = [l + 1, r + 1]
            ans = r - l
        
    elif hsh[a[r + 1]] == 0 and cnt == k:#when I can't accomodate
        while(cnt == k):#look to remove a character from segment
            if hsh[a[l]] == 1:
                cnt -= 1
                hsh[a[l]] -= 1
                l += 1
                break
            else:
                hsh[a[l]] -= 1
                l += 1
        r += 1
        hsh[a[r]] += 1
        cnt += 1
        if r - l > ans:
            idx = [l + 1, r + 1]
            ans = r - l
    elif hsh[a[r + 1]] != 0:
        r += 1
        hsh[a[r]] += 1
        if r - l > ans:
            idx = [l + 1, r + 1]
            ans = r - l
        
print(*idx)
                
            
    



        
        
