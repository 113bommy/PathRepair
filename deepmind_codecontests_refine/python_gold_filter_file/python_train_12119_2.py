a=int(input())
x=list(map(int,input().split()))
fixed=0
y=[-1 for i in range(a)]
for i in range(a):
    if x[i]==i:
        fixed+=1
    else:
        y[x[i]]=i

for i in range(a):
    if x[i]!=i:
        if x[i]==y[i]:
            print(fixed+2)
            quit()

else:
    print(min(a,fixed+1))
