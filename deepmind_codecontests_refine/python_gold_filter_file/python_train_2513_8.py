n=int(input())
a=input()
s=0
for i in range(n):
    if int(a[i])%2==0:
        s+=i+1
print(s)
