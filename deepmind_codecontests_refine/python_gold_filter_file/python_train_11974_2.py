t=input()
p=input()
lt=len(t)
lp=len(p)
for i in range(lt-lp+1):
    if t[i:i+lp]==p:print(i)