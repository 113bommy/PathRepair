a=int(input())-1
b=sorted((map(int,input().split())))
p=0
c=0
while p<a:
    if b[p+1]<=b[p]:c+=b[p]-b[p+1]+1;b[p+1]=b[p]+1
    p+=1
print(c)
