n,k,t=map(int,input().split())
if(k>=t):
    print(t)
elif(k<t and t<=n):
    print(k)
else:
    print(k+n-t)