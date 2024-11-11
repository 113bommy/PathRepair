n=int(input())
x=input()
c=0
for i in range(n):
    if(int(x[i])%2==0):
        c+=i+1
print(c)