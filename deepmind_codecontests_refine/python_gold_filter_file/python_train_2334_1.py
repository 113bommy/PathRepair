k=int(input())
array = [ str(input()) for i in range(4)]
a=[]
for i in range(1,10):
    l=str(i)
    c=0
    for j in range(4):
        c+=array[j].count(l)
    a.append(c)
if max(a)<=2*k:
    print("YES")
else:print("NO")