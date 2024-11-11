n=int(input())
s=list(map(int,input().split()))
swap=[0 for i in range(n+1)]
for i in range(0,2*n,2):
    if s[i]==s[i+1]:
        swap[s[i]]=1
cnt=0
for i in range(0,2*n,2):
    if swap[s[i]]==0 and s[i+1]!=s[i]:
        for j in range(i+1,2*n):
            if s[j]==s[i]:
                cnt+=j-i-1
                k=s[i+1]
                for l in range(j,i+1,-1):
                    s[l]=s[l-1]
                s[i+1]=s[i]
                swap[s[i]]=1
                break
print(cnt)