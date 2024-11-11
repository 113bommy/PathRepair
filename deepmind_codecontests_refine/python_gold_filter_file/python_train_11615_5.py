a=int(input())
b=list(map(int,input().split(':')))
out=''
if b[1]//10>=6:
    b[1]=10+b[1]%10
else:
    if b[1]<10:b[1]='0'+str(b[1])
if a==12:
    if not(12>=b[0]>0):
        
        b[0]='0'+str(b[0]%10)
        if b[0]=='00':b[0]='10'
else:
    if not(23>=b[0]>-1):
        b[0]='0'+str(b[0]%10)
if len(str(b[0]))==1:b[0]='0'+str(b[0])
print(str(b[0])+':'+str(b[1]))
