n=int(input())
a,b=input().split()
a,b=int(a),int(b)
z=[0]*101
for i in range(n-1):
    S,E=input().split()
    for i in range(int(S)+1,int(E)+1):
        z[i]=1
#print(z)
print((b-a)-z[a+1:b+1].count(1))