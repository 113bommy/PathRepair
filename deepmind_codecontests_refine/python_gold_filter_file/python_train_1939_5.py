def diff(arr):
    ans=[]
    for i in range(1,len(arr),2):
        ans.append(arr[i]-arr[i-1])
    return sum(ans)

n=int(input())
a=list(map(int,input().split()))
a.sort()
real_ans=[]
for i in range(2*n-1):
    
    for j in range(i+1,2*n):
        b=a.copy()
        b.pop(i)
        b.pop(j-1)
        real_ans.append(diff(b))
print(min(real_ans))
        
        