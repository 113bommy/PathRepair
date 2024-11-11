a,b,k = map(int, input().split())
lis=[]
for i in range(1,1000):
    if a%i==0 and b%i==0:
        lis.append(i)
print(lis[-k])