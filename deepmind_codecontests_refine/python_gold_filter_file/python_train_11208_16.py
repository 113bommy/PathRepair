x=int (input())
c=input()
d=0
for i in range(x-2):
    if (c[i]==c[i+1]==c[i+2]=='x'):
        d+=1
print(d)