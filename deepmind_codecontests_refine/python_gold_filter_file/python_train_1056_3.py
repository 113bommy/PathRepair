n=int(input())
s=input()
t=0
for i in s:
    if(i=='-'):
        if(t>0):
            t=t-1
    else:
        t=t+1
print(t)