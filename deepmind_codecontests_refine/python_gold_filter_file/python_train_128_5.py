def lcs(str1,str2):
    
    n=len(str1)
    m=len(str2)
    dp=[[0 for i in range (m+1)]for j in range (n+1)]
    
    for i in range(n-1,-1,-1):
        for j in range(m-1,-1,-1):
            if str1[i]==str2[j]:
                dp[i][j]=1+dp[i+1][j+1]
            else:
                dp[i][j]=max(dp[i+1][j],dp[i][j+1])
    return dp[0][0]

def printIntersection(arr1, arr2, m, n): 
    i,j = 0,0
    li=[]
    arr1.sort()
    arr2.sort()
    while i < m and j < n: 
        if arr1[i] < arr2[j]: 
            i += 1
        elif arr2[j] < arr1[i]: 
            j+= 1
        else: 
            li.append(arr2[j])
            j += 1
            i += 1
    return li[0]
    
t=int(input())
while t>0:
    n,m=[int(ele) for ele in input().split()]
    li=[int(ele) for ele in input().split()]
    li1=[int(ele) for ele in input().split()]
    ans=lcs(li,li1)
    if ans==0:
        print("NO")
    else:
        print("YES")
        print("1",end=" ")
        print(printIntersection(li,li1,n,m))
    t=t-1