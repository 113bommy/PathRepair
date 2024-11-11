x=input()
y=input().split()
k=[]
li=list(y)
k.append(li.count("1"))
k.append(li.count("2"))
k.append(li.count("3"))
m=min(k)
print(m)
for i in range(m):
    a=li.index("1")
    b=li.index("2")
    c=li.index("3")
    print(a+1,b+1,c+1)
    li[a]=5
    li[b]=5
    li[c]=5