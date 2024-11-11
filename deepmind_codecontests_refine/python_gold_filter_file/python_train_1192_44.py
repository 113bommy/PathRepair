r= input()
s= input()
k1='qwertyuiop'
k2='asdfghjkl;'
k3='zxcvbnm,./'
totk= k1+k2+k3
ans=''
if r=='R':
    
    for i in range(len(s)):
        ans=ans+ totk[totk.index(s[i])-1]
else:
    for i in range(len(s)):
        ans+= totk[totk.index(s[i])+1]

print(ans)