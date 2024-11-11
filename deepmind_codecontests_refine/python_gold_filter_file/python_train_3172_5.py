a,b=[],[]
for i in range(int(input())):
    x,y=input().split()
    a.append(int(x))
    b.append(int(y))
print(max(max(a)-min(a),max(b)-min(b))**2)