n,c = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
dp = []
for i in range(n):
    temp = []
    if i==0:
        temp.append(0)
        temp.append(c)
        dp.append(temp)
    else:
        t1 = dp[i-1][0] + a[i-1]
        t2 = dp[i-1][0] + b[i-1] + c
        t3 = dp[i-1][1] + a[i-1]
        t4 = dp[i-1][1] + b[i-1]
        temp.append(min(t1,t3))
        temp.append(min(t2,t4))
        dp.append(temp)
        #print(t1,t2,t3,t4)
    print(min(temp),end=" ")

