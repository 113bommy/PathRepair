n=int(input())
s=input()
m=input()
r,w=n,0
p=str(s)
o=str(m)
for i in s:
    if i in m:r-=1;m=m.replace(i,"",1);s=s.replace(i,"",1)
l=[str(i) for i in range(10)]
for i in s:
    for j in l:
        if i<j and j in m:m=m.replace(j,"",1);r-=1;break
for i in p:
    for j in l:
        if i<j and j in o:o=o.replace(j,"",1);w+=1;break
print(r,w,sep="\n")