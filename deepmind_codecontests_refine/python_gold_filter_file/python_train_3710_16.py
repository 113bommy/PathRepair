from math import ceil as ceil
h1,a1,c1 = map(int, input().split())
h2,a2 = map(int, input().split())
s=''
while h2>0:
    if h1>a2 or a1>=h2:
        s+='s'
        h2-=a1
        h1-=a2
    else:
        s+='h'
        h1+=c1
        h1-=a2
print(len(s))
for i in s:
    if i=='s':
        print('STRIKE')
    else:
        print('HEAL')
        
