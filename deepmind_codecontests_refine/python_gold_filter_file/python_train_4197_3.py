a=input()
z=len(a)
d=[];t=""
for i in a:
    if i.isalpha() :t+=i
    else:
        if t!="":d.append(t)
        if i in '.,?!':d.append(i)
        t=""
d.append(t)
p=len(d)
for i in range(p-1):
    if d[i+1] in".,?!":print(d[i],end="")
    else:print(d[i],end=" ")
print(d[-1])