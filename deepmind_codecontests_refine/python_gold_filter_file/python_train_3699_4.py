#!/usr/bin/python3.5

n=int(input())
s=input()
b=s.count(s[0])
if b==n:
    print(s[0])
    quit()
k=0
o=''
b=s.count('B')
if b:
   k+=1
else:
    o+='B'
g=s.count('G')
if g:
   k+=1
else:
    o+='G'
r=s.count('R')
if r:
   k+=1
else:
    o+='R'
if n==2:
    print(o)
    quit()

if k==3:
    print("BGR")
    quit()

if b and g:
    if b>g and g<2:
        o+='G'
    elif g>b and b<2:
        o+='B'
    else:
        o+='GB'
elif b and r:
    if b>r and r<2:
        o+='R'
    elif r>b and b<2:
        o+='B'
    else:
        o+='BR'
elif g>r and r<2:
    o+='R'
elif r>g and g<2:
    o+='G'
else:
    o+='RG'
del k
k=list(o)
k.sort()
for i in k:
    print(i,end='')
print()