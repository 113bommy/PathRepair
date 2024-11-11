#Add odd or subtract even
t = int(input())
s = ''
for i in range(t):
    c = 0
    a,b = map(int,input().split())
    if a<b:
        if (b-a)%2==0:
            c = 2
        else:
            c = 1
    if a>b:
        if (a-b)%2!=0:
            c = 2
        else:
            c = 1
    s+=str(c)+' '
print(s.replace(' ','\n'))