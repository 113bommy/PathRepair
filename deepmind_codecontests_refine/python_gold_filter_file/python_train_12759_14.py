a=[*input()]
n=len(a)
i=0
while i<n and a[i]=='a':i+=1
if i==n:a[-1]='z'
while i<n and a[i]!='a':a[i]=chr(ord(a[i])-1);i+=1
print(''.join(a))