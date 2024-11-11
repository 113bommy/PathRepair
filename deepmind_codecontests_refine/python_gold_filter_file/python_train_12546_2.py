a,b,c,t=input(),list(map(int,input().split())),10**9,0
for i in b:
    if i%2:c=min(c,i);t=[0,1][[0,1].index(t)-1]
print(sum(b)-c if t else sum(b))