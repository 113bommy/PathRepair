l=list(input())
l.pop(0)
l.pop(-1)
h=list(set(l))
a1=len(h)
if a1==0:
    print(0)
elif a1==1:
    print(a1)
else:
    print(a1-2)
