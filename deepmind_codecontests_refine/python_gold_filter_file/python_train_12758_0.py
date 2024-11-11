a=input().replace(""," ").split();l=len(a);r=-1;ok=False
for i in range(len(a)):
    if a[i]!='a' and not(ok):l=i;r=i;ok=True
    if ok:
        if a[i]=='a':break
        else:r=i
if not(ok):a[-1]='z';print(*a,sep="");exit()
for i in range(len(a)):
    if l<=i and r>=i:
        print(chr(ord(a[i])-1),end="")
    else:print(a[i],end="")