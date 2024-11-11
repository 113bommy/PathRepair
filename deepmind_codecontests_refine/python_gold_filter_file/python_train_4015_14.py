n=int(input())
cw=list(input())
size=[]
c=0
i=0
st=-1
while i<=n-1:
    if cw[i]=='B' and st==-1:
        c+=1
        st=i
    if cw[i]=='W':
        if st!=-1:
            size.append(i-st)
            st=-1
    if i==n-1 and cw[i]=='B':
        if st!=-1:
            size.append(i-st+1)
            st=-1
    i+=1
print(c)
for i in range(len(size)):
    print(size[i],end=" ")
