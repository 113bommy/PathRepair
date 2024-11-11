N=int(input())
ans=[]
for _ in range(N):
    m=int(input())
    A=list(map(int,input().split()))
    A.sort()
    even=0
    odd=0
    one=0
    for i in range(m-1):
        if A[i]%2==0:
            even+=1
        else:
            odd+=1
        if A[i+1]-A[i]==1:
            one+=1
    if A[m-1]%2==0:
        even+=1
    else:
        odd+=1
    if even%2==0:
        ans.append("YES")
    elif one>=1:
        ans.append("YES")
    else:
        ans.append("NO")
for i in ans:
    print(i)