n=int(input())
a=0
y1=0
for i in range(n):
    x,y=[int(i) for i in input().split()]
    if x<0:
        a+=1
    else:
        y1+=1
if a<=1 or y1<=1:
    print('YES')
else:
    print('NO')
