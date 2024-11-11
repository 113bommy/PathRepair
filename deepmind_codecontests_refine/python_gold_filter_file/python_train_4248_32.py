x=int(input())
s=0
if x%2==0:
    p=10
    while(p<=x):
        s+=x//p
        p*=5
print(s)    