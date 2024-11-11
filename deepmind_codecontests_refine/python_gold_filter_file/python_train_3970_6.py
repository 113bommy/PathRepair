n=int(input())
a=[];d={}
for _ in range((2*n)-2):
    a.append(input())
    
for i in range(len(a)):
    if len(a[i]) in d:
        d[len(a[i])].append(i)
    else:
        d[len(a[i])]=[i]
x,y=a[d[max(d)][0]],a[d[max(d)][1]]
pref,suff=x,y
if pref[1:]!=suff[:-1]:
    pref,suff=y,x

b=['']*(len(a))

w='';flag=0;flagx=0
for i in pref:
    w+=i;flag=0
    for j in range(len(a)):
        if a[j]==w and b[j]=='':
            b[j]='P'
            flag=1
            break
    if flag==0:
        flagx=1
        b=['']*(len(a))
        break
#print(b)
if flagx==1:
    w=''
    for i in suff:
        w+=i;flag=0
        for j in range(len(a)):
            if a[j]==w and b[j]=='':
                b[j]='P'
                #flag=1
                break
for i in range(len(b)):
    if b[i]=='':
        b[i]='S'

print(''.join(b))
