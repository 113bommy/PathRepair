n=int(input());
count=0;
for i in range(1,n+1):
    d=input();
    p,q=map(int,d.split());
    if q-p>=2:
        count=count+1;
print(count)   