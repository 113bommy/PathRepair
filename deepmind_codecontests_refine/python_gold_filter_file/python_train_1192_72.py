s="qwertyuiopasdfghjkl;zxcvbnm,./"
s1=input()
s2=input()

ans=""
if(s1=='R'):
    for i in range(len(s2)):
        ch=s2[i]
        for j in range(len(s)):
            if(ch==s[j]):
                ans=ans+s[j-1]
            
            
else:
    for i in range(len(s2)):
        ch=s2[i]
        for j in range(len(s)):
            if(ch==s[j]):
                ans=ans+s[j+1]
        
print(ans)