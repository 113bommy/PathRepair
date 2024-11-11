# cook your dish here
o=0
d=0
s = input()
for i in s:
    if i=='o':
        o+=1
    else:
        d+=1
if o==0:
    print("YES")
elif d%o == 0:
    print("YES")
elif d==0:
    print("YES")
else:
    print("NO")
