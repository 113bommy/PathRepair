n=int(input())
s=input()
c1=c2=0
for i in s:
    if i=='L':
        c1+=1
    else:
        c2+=1
print(c1+c2+1)