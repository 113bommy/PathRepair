n=int(input())
a=int(n//10)
b=int(n%10)

if a==0:
    x=1
if a==1:
    x=6
if a==2:
    x=1
if a==3:
    x=2
if a==4:
    x=2
if a==5:
    x=3
if a==6:
    x=1
if a==7:
    x=4
if a==8:
    x=0
if a==9:
    x=1

if b==0:
    y=1
if b==1:
    y=6
if b==2:
    y=1
if b==3:
    y=2
if b==4:
    y=2
if b==5:
    y=3
if b==6:
    y=1
if b==7:
    y=4
if b==8:
    y=0
if b==9:
    y=1

print ((x+1)*(y+1))
