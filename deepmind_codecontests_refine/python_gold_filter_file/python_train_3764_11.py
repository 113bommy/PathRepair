s1=input().split()
s=[]
for i in range(4):
    k=int(s1[i])
    s.append(k)

s=sorted(s)
a=int(s[3])-int(s[0])
b=int(s[3])-int(s[1])
c=int(s[3])-int(s[2])

print(a,b,c)