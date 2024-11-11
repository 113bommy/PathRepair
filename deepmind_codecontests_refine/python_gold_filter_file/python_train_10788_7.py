pos=neg=c=0
for _ in range(int(input())):
    x,y=map(int,input().split())
    if x<0:neg+=1
    else: pos+=1
    c+=1
print('Yes' if pos==1 or neg==1 or pos==c or neg==c else 'No')