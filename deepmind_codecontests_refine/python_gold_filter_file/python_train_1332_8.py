s=list(input())
cnt=0
now=''
buf=''
for i in range(len(s)):
    now+=s[i]
    if buf!=now:
        buf=now
        now=''
        cnt+=1
print(cnt)
