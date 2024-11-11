l=list(input())
s=list(input())
sadonok=["a","e","i","o","u"]
hamsado=["q","w","r","t","y","p","s","d","f","g","h","j","k","l","z","x","c","v","b","n","m"]
s1,s2="",""
for i in range(len(l)):
    if l[i] in sadonok:
        s1+="1"
    else:
        s1+="0"
for i in range(len(s)):
    if s[i] in sadonok:
        s2+="1"
    else:
        s2+="0"
if s1==s2:
    print("Yes")
else:
    print("No")
