from string import ascii_uppercase
n,k=map(int,input().split())
s=list(input().split())
#print(len(s))
names=[]
for i in ascii_uppercase:
    names.append(i)
    names.append('A'+str(i).lower())
#print(names)
a=[]
if s[0]=='YES':
    for i in range(k):
        a.append(names[i])
elif s[0]=='NO':
    for i in range(k-1):
        a.append(names[i])
    a.append(names[0])
for j in range(1,len(s)):
    #print(j)
    if s[j]=='YES':
        a.append(names[k-1+j])
    else:
        a.append(a[j])
print(*a)