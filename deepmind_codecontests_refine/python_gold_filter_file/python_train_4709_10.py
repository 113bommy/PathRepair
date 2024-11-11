string=input()
n=len(string)
k=0
if len(string)==1 and string[0]>='a':
    #print('only one lower case')
    k=1
s=0
for i in range(1,n):
    if string[i]<='Z':
        s+=1
    else:
        break
if s==n-1:
    k=1
if k==1:
    print(string.swapcase())
else:
    print(string)
