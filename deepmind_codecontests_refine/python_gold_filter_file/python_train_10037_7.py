s=input()
c=1
dic={}
if len(s)==1:
    print(s)
else:
    l=-1
    for i in range(1,len(s)):
        if s[i]==s[i-1]:
            c+=1
        if s[i]!=s[i-1]:
            if c>=2 and l>=2:
                l=1
            else:
                l=c
            c=1
        if l>=2 and c>=2:
            dic[i]=1
        elif c>2:
            dic[i]=1
    ans=''
    for i in range(len(s)):
        if i not in dic:
            ans=ans+s[i]
    print(ans)
