s=input()
s1=0
s2=0
s3=0
s4=0
s5=0
l=[]
for h in s:
    l.append(h)
for i in range(len(l)):
    if l[i]=='h':
        s1+=1
        del l[0:i]
        break
for i in range(len(l)):
    if l[i]=='e':
        s2+=1
        del l[0:i]
        break
for i in range(len(l)):
    if l[i]=='i':
        s3+=1
        del l[0:i]
        break
for i in range(len(l)):
    if l[i]=='d':
        s4+=1
        del l[0:i]
        break
for i in range(len(l)):
    if l[i]=='i':
        s5+=1
        del l[0:i]
        break
if s1==1 and s2==1 and s3==1 and s4==1 and s5==1:
    print('YES')
else:
    print('NO')
