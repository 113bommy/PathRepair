a=int(input())
s=input()
n=len(s)
pri=pow(10,9)+7
dp=[[[0,0,0] for i in range(3)] for i in range(len(s))]
ans=[1]
for i in range(a+1):
    ans.append((ans[-1]*3)%pri)
cnt=0
for i in range(len(s)):
    if(s[i]=='a'):
        if(i==0):
            dp[i][0][0]+=1
        else:
            dp[i][0][0]=(dp[i-1][0][0]+dp[i-1][1][0]+dp[i-1][2][0]+ans[cnt])%pri
            dp[i][0][1]=(dp[i-1][0][1]+dp[i-1][1][1]+dp[i-1][2][1])%pri
            dp[i][0][2]=(dp[i-1][0][2]+dp[i-1][1][2]+dp[i-1][2][2])%pri
    elif(s[i]=='b'):
        if(i!=0):
            dp[i][1][0]=(dp[i-1][0][0]+dp[i-1][1][0]+dp[i-1][2][0])%pri
            dp[i][1][2]=(dp[i-1][0][2]+dp[i-1][1][2]+dp[i-1][2][2])%pri
            dp[i][1][1]=(dp[i][1][0]+(dp[i-1][0][1]+dp[i-1][1][1]+dp[i-1][2][1]))%pri
    elif(s[i]=='c'):
        if(i!=0):
            dp[i][2][0]=(dp[i-1][0][0]+dp[i-1][1][0]+dp[i-1][2][0])%pri
            dp[i][2][1]=(dp[i-1][0][1]+dp[i-1][1][1]+dp[i-1][2][1])%pri
            dp[i][2][2]=(dp[i][2][1]+(dp[i-1][0][2]+dp[i-1][1][2]+dp[i-1][2][2]))%pri
    else:
        cnt+=1
        if(i==0):
            dp[0][0][0]+=1
            
            continue;
            
        dp[i][0][0]=(dp[i-1][0][0]+dp[i-1][1][0]+dp[i-1][2][0]+ans[cnt-1])%pri
        dp[i][0][1]=(dp[i-1][0][1]+dp[i-1][1][1]+dp[i-1][2][1])%pri
        dp[i][0][2]=(dp[i-1][0][2]+dp[i-1][1][2]+dp[i-1][2][2])%pri

        dp[i][1][0]=(dp[i-1][0][0]+dp[i-1][1][0]+dp[i-1][2][0])%pri
        dp[i][1][2]=(dp[i-1][0][2]+dp[i-1][1][2]+dp[i-1][2][2])%pri
        dp[i][1][1]=(dp[i][1][0]+(dp[i-1][0][1]+dp[i-1][1][1]+dp[i-1][2][1])%pri)%pri

        dp[i][2][0]=(dp[i-1][0][0]+dp[i-1][1][0]+dp[i-1][2][0])%pri
        dp[i][2][1]=(dp[i-1][0][1]+dp[i-1][1][1]+dp[i-1][2][1])%pri
        dp[i][2][2]=(dp[i][2][1]+(dp[i-1][0][2]+dp[i-1][1][2]+dp[i-1][2][2])%pri)%pri





print((dp[n-1][0][2]+dp[n-1][1][2]+dp[n-1][2][2])%pri)
         

          
