s=input()
s=s.replace(' ','')
l=len(s)-2
w=['A','E','I','O','U','Y','a','e','i','o','u','y']
f=0
for i in w:
    if(i==s[l]):
        f=0
        break
    else:
        f=1
if(f==0):
    print("YES")
else:
    print("NO")