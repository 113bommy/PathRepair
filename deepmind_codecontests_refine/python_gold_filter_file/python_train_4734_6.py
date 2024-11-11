n=input()
z=[]
for i in n:
    z.append(i)
z.remove("?")
m=""
for j in z:
    m=m+j
m=m.strip()
m=m.lower()
if m[len(m)-1] in "euioay":
    print("YES")
else:
    print("NO")
