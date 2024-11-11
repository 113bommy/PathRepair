n = int(input())
a = n//36
rema = n%36
if(rema==35):
    a+=1
if(a>=n):
    b=0
else:
    b = (n-a*36)//3
    rem = (n-a*36)%3
    if(rem==2):
        b+=1
print(a,b)