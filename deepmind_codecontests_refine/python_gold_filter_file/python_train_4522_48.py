a=input()
b=input()
c,d=ord(a[0])-ord(b[0]),ord(a[1])-ord(b[1])
#print(c,d)
print(max(c,-c,d,-d))
while c!=0 or d!=0:
    r=''
    if c<0:r='R';c+=1
    if c>0:r='L';c-=1
    if d<0:r+='U';d+=1
    if d>0:r+='D';d-=1
    print(r)