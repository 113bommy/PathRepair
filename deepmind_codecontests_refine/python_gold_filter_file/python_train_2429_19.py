n = input()
n=input()
m=list(str(n))

firststr=m[:int(len(m)/2)]
secondstr=m[int(len(m)/2):]

firststr.sort() 
secondstr.sort()
k=0
l=0
for i in range(0,len(firststr)):
    if (firststr[i]>secondstr[i]):
        k=k+1
    if (firststr[i]<secondstr[i]):
        l=l+1
if (k==len(firststr) or l==len(firststr)):
    print('YES')
else:
    print('NO')