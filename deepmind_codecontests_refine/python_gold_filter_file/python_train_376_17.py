a=int(input())
b=int(input())
if a>b:
    d=a-b
else:
    d=b-a
if d%2==0:
    t=d//2*(d//2+1)
else:
    t=d//2*(d//2+1)+d//2+1
print(t)
    
