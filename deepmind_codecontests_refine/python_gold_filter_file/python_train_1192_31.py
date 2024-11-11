#474A
l1="qwertyuiop[]"
l2="asdfghjkl;'"
l3="zxcvbnm,./"
side=input()
s=input()
ans=""
if side=="R" :
    shift=-1
else :
    shift=1
for i in range(len(s)):
    if l1.find(s[i])!=-1:
        ans+=l1[l1.index(s[i])+shift]
    elif l2.find(s[i])!=-1:
        ans+=l2[l2.index(s[i])+shift]
    elif l3.find(s[i])!=-1:
        ans+=l3[l3.index(s[i])+shift]
print(ans)
            
