r,g,b = map(int,input().split())
s =[r//3+g//3+b//3]
if r>0 and g>0 and b>0:
    r-=1
    g-=1
    b-=1
    s.append(r//3+g//3+b//3+1)
if r>0 and g>0 and b>0:
    r-=1
    g-=1
    b-=1
    s.append(r//3+g//3+b//3+2)
if r>0 and g>0 and b>0:
    r-=1
    g-=1
    b-=1
    s.append(r//3+g//3+b//3+3)
s.sort()
print(s[-1])
