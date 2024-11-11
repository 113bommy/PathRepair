n=int(input())
l=list(map(int, input().split()))
ans=1
flag1, flag2=0, 0
prev1, prev2=0, 0
for i in range(n):
    if l[i]==1:
        flag1+=1
        if flag2!=0:
            prev2=flag2
            flag2=0
    else:
        flag2+=1
        if flag1!=0:
            prev1=flag1
            flag1=0
    if flag1<=prev2:
        ans=max(ans, flag1)
    if flag2<=prev1:
        ans=max(ans, flag2)
print(ans*2)