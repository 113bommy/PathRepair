a,b=open(0);c=1;
for i in sorted(b.split()):
    c*=int(i)
    if c>10**18:print(-1);exit()
print(c)