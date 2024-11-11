n=int(input())
s=input()
l=len(s)
c=0
if n%2!=0:
    print('1'+'\n'+s)

else:
    for i in s:
        if i=='0':
            c+=1
        else:
            c-=1
    if c==0:
        print('2')
        print(s[:l-1]+" "+s[l-1])
    else:
        print('1'+'\n'+s)
