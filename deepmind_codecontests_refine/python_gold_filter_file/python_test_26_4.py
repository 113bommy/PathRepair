def sfac(n):
    if(n==2):
        return 1
    elif(n==4):
        return 12
    elif(n==6):
        return 30*12
    ans=1
    for i in range(3,n+1):
        # print(ans,i)
        ans*=i
        ans=ans%1000000007
        # print(ans)
    return ans
for fghj in range(int(input())):
    n=int(input())
    print(sfac(2*n))