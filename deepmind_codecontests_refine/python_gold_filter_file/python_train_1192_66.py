s2=input()
s1=input()
ans=""
s="qwertyuiopasdfghjkl;zxcvbnm,./"
if s2=="R":
    for i in s1:
        for j in range(len(s)):
            if i==s[j]:
                ans=ans+s[j-1]
else:
    for k in s1:
        for m in range(len(s)):
            if k==s[m]:
                ans=ans+s[m+1]
print(ans)                
                
    
