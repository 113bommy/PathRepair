n = int(input())
s = list(input())
cou=[[0]*n for i in range(2)]
if s[0]=='0':
    cou[0][0]=1
    cou[1][0]=0
else:
    cou[0][0]=0
    cou[1][0]=1  
for i in range(1,n):
    if s[i]=='0':
        cou[0][i]=cou[0][i-1]+1
        cou[1][i]=cou[1][i-1]
    else:
        cou[0][i]=cou[0][i-1]
        cou[1][i]=cou[1][i-1]+1
if n==1:
    print(1)
    print(*s)
    exit()
if cou[0][-1]!=cou[1][-1]:
    print('1')
    print(*s,sep='')
    exit()
for i in range(n):
    a=cou[0][i]
    b=cou[1][i]
#    print(a,b,cou[0][-1]-a,cou[1][-1]-b)
    if a!=b and (cou[0][-1]-a !=cou[1][-1]-b):
        print('2')
        print(*s[:i+1],sep='',end=' ')
        print(*s[i+1:],sep='')
        exit()
print('3')
print(s[0],' ',s[1],' ',*s[2:],sep='')        
    