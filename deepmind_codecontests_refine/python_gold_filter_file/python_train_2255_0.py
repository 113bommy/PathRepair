def binary_search(arr, low, high, x): 
    if high >= low: 
        mid = (high + low) // 2
        if arr[mid] == x: 
            return mid 
  
        elif arr[mid] > x: 
            return binary_search(arr, low, mid - 1, x) 
        else: 
            return binary_search(arr, mid + 1, high, x) 
  
    else: 
        
        return low

n,q=(map(int,input().split()))
a=list((map(int,input().split())))
k=list(map(int,input().split()))
su=[]
su.append(a[0])
bb=[]
for i in range(1,n):
    su.append(su[i-1]+a[i])
pre=0   
for i in range(q):
    ii=binary_search(su,0,n-1,pre+k[i])
    if ii==n:
        bb.append(n)
        pre=0
    else:
        
        if su[ii]==(pre+k[i]):
            if (n-1-ii)==0:
                bb.append(n)
                pre=0
            else:
                bb.append((n-1-ii))
                pre+=k[i]
        else:
            bb.append((n-1-ii)+1)
            pre+=k[i]
        
    
   
    
for ele in bb:
    print(ele)