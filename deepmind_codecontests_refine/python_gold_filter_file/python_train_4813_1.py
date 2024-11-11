t=int(input())
while t:
    a,b,c=map(int,input().split())
    ans=[10**18,a,b,c]
    for i in range(1,2*10**4+1):
        for j in range(0,2*10**4+1,i):
            if(j==0):continue
            if(c%j<j-c%j):temp=[abs(i-a)+abs(j-b)+c%j,i,j,c-c%j]
            else:temp=[abs(i-a)+abs(j-b)+j-c%j,i,j,c+j-c%j]
            if(temp[0]<ans[0]):
                ans=temp
    print(ans[0])
    print(ans[1],ans[2],ans[3])
    t-=1