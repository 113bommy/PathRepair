def printp(a,b,c):
    s=''
    for i in range(a):
        s=s+'|'
    s=s+'+'
    for i in range(0,b):
        s=s+'|'
    s=s+'='
    for i in range(0,c):
        s=s+'|'
    return s
s=str(input())
plus=s.index('+')
equal=s.index('=')
a=len(s[:plus])
b=len(s[plus+1:equal])
c=len(s[equal+1:])
if((a+b)==c):
    print(s)
elif((a+1)+b==c-1 or (b+1)+a==c-1 or (b-1)+a==c+1 or (a-1)+b==c+1):
    if((a+1)+b==c-1 and c>=2):
        print(printp(a+1,b,c-1))
    elif((b+1)+a==c-1 and c>=2):
        print(printp(a,b+1,c-1))
    elif((b-1)+a==c+1 and b>=2):
        print(printp(a,b-1,c+1))
    elif((a-1)+b==c+1 and a>=2):
        print(printp(a-1,b,c+1))
else:
    print('Impossible')
    