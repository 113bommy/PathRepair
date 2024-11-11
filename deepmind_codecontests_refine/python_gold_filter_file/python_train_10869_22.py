n = int(input())
a = list(map(int,input().split()))
x = []
y=[]
x.append(abs(a[-1]-a[0]))
y.append([len(a),1])
for i in range (len(a)-1):
    x.append(abs(a[i]-a[i+1]))
    y.append([i+1,i+2])
v = 1000000000
for i in range(len(x)):
    if(x[i]<v):
        v=x[i]
        f=y[i]

    
print(f[0],f[1])

    
        