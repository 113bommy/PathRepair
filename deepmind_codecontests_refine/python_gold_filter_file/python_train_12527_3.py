import sys
s=sys.stdin.readline()
k=0
a=1
dp=[]
e=0
lendp=0
r=""
for x in s:
    if x==".":
        dp+=[k]
        lendp+=1
        if e==0:
            
            a=0
            if k>8 or k==0:
                a=1
                break
            e=1
        else:
            if k>11 or k<=1:
                a=1
                break
        k=0
    else:
        k+=1
if e==1:
    dp+=[k]
    if k==1 or k>4:
        a=1
if a==1:
    print("NO")
else:
    j=0
    print("YES")
    for i in range(lendp):
        if dp[i+1]>3:
            print(s[j:j+dp[i]+4])
            j+=dp[i]+4
            dp[i+1]-=3*(i<lendp)
        elif dp[i+1]==2:
            print(s[j:j+dp[i]+2])
            j+=dp[i]+2
            dp[i+1]-=i<lendp
        else:
            print(s[j:j+dp[i]+3])
            j+=dp[i]+3
            dp[i+1]-=2*(i<lendp)
