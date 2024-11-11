n,k = map(int,input().split())
a = 'qwertyuiopasdfghjklzxcvbnm'
s = ''
for i in range(k):
    s+=a[i]
n-=k
i = 0
while(n):
    s+=s[i]
    i+=1
    n-=1
print(s)