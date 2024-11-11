n=input()
m=input()
a=''
c=0
for i in range(len(n)):
    if n[i]==m[i]:
        a+=n[i]
    else:
        c+=1
        a+=[n[i],m[i]][c%2]
    if i==(len(n)-1) and c%2:
        exit(print('impossible'))
print(a)