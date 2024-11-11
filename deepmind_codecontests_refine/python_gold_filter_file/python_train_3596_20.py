a,b=map(int,input().split());z=0
for case in ' '*a:
    c=int(input().replace(' ',''))
    b=b+c
    if b<0:z+=1;b=b-c
print(b,z)