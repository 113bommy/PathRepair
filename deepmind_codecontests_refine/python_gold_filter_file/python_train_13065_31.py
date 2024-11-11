a,b=input().split()
a=int(a)
b=int(b)
n=0
for i in range(a):
    c=input().split()
    for i in range(0,b*2,2):
        if c[i]=='1' or c[i+1]=='1':
            n+=1
print(n)            