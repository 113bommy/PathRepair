import sys
a=0
b=0
c={'Q':9,'R':5,'B':3,'N':3,'P':1}
for i in sys.stdin:
    for j in i:
        if j in c.keys():a+=c[j]
        elif j.upper()in c.keys():b+=c[j.upper()]
if a>b:print('White')
elif a<b:print('Black')
else:print('Draw')
