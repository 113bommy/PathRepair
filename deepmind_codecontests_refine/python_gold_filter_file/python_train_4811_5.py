n, k = map(int, input().split())
a    = [int(x) for x in input()]

def check(a, n, k):
    flg=True
    for i in range(k, n, k):
        for j in range(k):
            if i+j<n:
                if a[i+j] > a[j]:
                    return False
                elif a[i+j] < a[j]:
                    return True
        if flg==False:
            break
    return flg        

def add(arr, k):
    r        = 1
    for i in range(k-1, -1, -1):
        temp = r
        r        = (arr[i] + temp) // 10
        arr[i]   = (arr[i] + temp) % 10
        
    return arr    

def make(arr, k, n):
    ans=[]
    while len(ans) < n:
        ans.extend(arr[:min(k, n-len(ans))])
    return ans    

if check(a, n, k) == True:
    ans = make(a, k, n)
else:
    ans = make(add(a[:k], k), k, n)

print(n)    
print(''.join(str(x) for x in ans))    

#4 2
#1234