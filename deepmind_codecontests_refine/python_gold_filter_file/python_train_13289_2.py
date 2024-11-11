def num(n):
    return ('7'*((n)//2)+'4'*((n)//2))
def lucky(n):
    c4=0
    c7=0
    for i in str(n):
        if(i=='4'):
            c4+=1
        elif(i=='7'):
            c7+=1
        else:
            return False
    if(c4==c7):
        return True
    return False
    
s=input()
c4=0
c7=0
n=len(s)
ans=''
if(len(s)%2==1):
    print('4'*((n+1)//2)+'7'*((n+1)//2))
    exit()
if(int(s)>int(num(n))):
    print(num(n+2)[::-1])
    exit()
if(int(s)<int(num(n)[::-1])):
    print(num(n)[::-1])
    exit()
ans=int(s)
while(True):
    if(lucky(ans)):
        print(ans)
        break
    ans+=1