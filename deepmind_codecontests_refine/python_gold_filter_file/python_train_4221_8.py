a=int(input())
s=0

while a:
    if a%8==1:
        s+=1
    a=a//8

print(s)