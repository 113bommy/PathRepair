a,b,n=map(int,input().split())
flag=0
for x in range(-1001, 1001):
     if a*pow(x,n)==b:
         print(x)
         flag=1
         break;
if flag==0:
    print('No solution')