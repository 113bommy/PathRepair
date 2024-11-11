n=int(input())
s=input()
mn=s
for shift in range(n):
    copy=s[n-shift:]+s[:n-shift]
    for add in range(10):
        ans=''
        for dig in range(n):
            ans+=str((int(copy[dig])+add)%10)
        if(int(ans)<int(mn)):
            mn=ans
print(mn)