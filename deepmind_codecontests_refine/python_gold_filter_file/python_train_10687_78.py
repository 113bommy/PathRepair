s=input().split()
a=int(s[0])
k=int(s[1])
for i in range(k):
    if(a%10==0):
        a=a//10
    else:
        a-=1
print(a)
         