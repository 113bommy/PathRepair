x=int(input());t=0
for i in range(x):
    l=lambda:map(int,input().split());y=list(l())
    if(y[1]-y[0]>=2):
        t=t+1
    else:
        continue
print(t)



