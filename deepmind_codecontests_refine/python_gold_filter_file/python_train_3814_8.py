months=[31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31]
n=int(input())
arr=list(map(int,input().split()))
ans=0  
for i in range(len(months)):
    flag=0 
    for j in range(n):
        if arr[j]!=months[(i+j)%len(months)]:
            flag=1 
            break
    if flag==0:
        ans=1 
        break 
if ans==1:
    print("YES")
else:
    print("NO")
        