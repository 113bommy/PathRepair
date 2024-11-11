s=input()
n=len(s)

cnt=0
ans=0

for i in range(n-1):
    if s[i]=="A":
        cnt+=1
    elif s[i:i+2]=="BC":
        ans+=cnt
    elif i>0 and s[i-1:i+1]=="BC":
        pass
    else:
        cnt=0

print(ans)
    