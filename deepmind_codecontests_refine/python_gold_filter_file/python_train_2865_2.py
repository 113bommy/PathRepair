from typing import AnyStr


ai=input()
p=input()
la=len(ai)
lp=len(p)
a=list(ai)

count=0
for i in range(0,la-lp+1):
    if a[i:i+lp]==list(p):
        count+=1
        a[i+lp-1]='#'
print(count)    