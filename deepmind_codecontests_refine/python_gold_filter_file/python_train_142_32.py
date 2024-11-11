a=input()
b=[]
for i in range(0,len(a),2):
    b+=[a[i]]
b.sort()
output=b[0]
for n in range(1,len(b)):
    output+='+'+b[n]
print(output)