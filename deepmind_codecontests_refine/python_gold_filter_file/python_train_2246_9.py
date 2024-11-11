a=int(input())
b=int(input())
c=a+b
a=list(str(a))
b=list(str(b))
c=list(str(c))
an=[];bn=[];cn=[]
for i in a:
    if i!="0":
        an.append(i)
for i in b:
    if i!="0":
        bn.append(i)
for i in c:
    if i!="0":
        cn.append(i)
if int("".join(an))+int("".join(bn))==int("".join(cn)):
    print("YES")
else:
    print("NO")
