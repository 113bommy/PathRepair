n=int(input())
a=[]
x=0
a=input().split()
for i in range(n):
    if a[i]=='1':
        x=1
if x==1:
    print('HARD')
else:
    print('EASY')