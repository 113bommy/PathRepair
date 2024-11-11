n=int(input())
def s(x):
    return sum(int(i) for i in str(x))
x=int(n**0.5)
diff=0 
ok=False 
while diff<=50 and x>=0:
    if x*x+s(x)*x==n:
        ok=True 
        break 
    diff+=1 
    x-=1 
if not ok:
    print(-1)
else:
    print(x)