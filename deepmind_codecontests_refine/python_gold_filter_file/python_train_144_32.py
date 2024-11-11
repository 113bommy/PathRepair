s=input('')
n,c=s.split(' ')
n=int(n)
c=int(c)
s1=input('')
l=s1.split(' ')
l1=[]
l=list(map(int,l))
for i in range(n-1):
    #print(i)
    if(l[i+1]<l[i]):
        l1.append(l[i]-l[i+1])
if(len(l1)==0):
    print('0')
else:
    if(c>max(l1)):
        print('0')
    else:
        print(max(l1)-c)