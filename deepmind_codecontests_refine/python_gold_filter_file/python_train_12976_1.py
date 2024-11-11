s=input();Ans=0;s=s[::-1]
if len(s)==1 and s[0]=='1':print(0)
elif s.index('1')==len(s)-1:print(len(s)-1)
else:
    t=s.index('1');
    Ans+=(t+2)
    for i in range(t+1,len(s)):
        if s[i]=='0':Ans+=2
        else:Ans+=1
    print(Ans)    
