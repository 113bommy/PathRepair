r,a,b,c,d=map(int,input().split())
t=(a-c)*(a-c)+(b-d)*(b-d)
t=t**(1/2)
if (t/r)/2==int((t/r)/2):
    print(int((t/r)/2))
else:
    print(int((t/r)/2)+1)





















































