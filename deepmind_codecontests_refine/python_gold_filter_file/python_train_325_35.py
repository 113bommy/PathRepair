n,x,y = [int(x) for x in input().split()]
s = input()
count=0
for i in range(1,y+1):
    if (s[-i]=='1'):
        count+=1
if s[-(y+1)] == '0':
    count+=1
for i in range(y+2,x+1):
    if(s[-i]=='1'):
        count+=1
print(count)