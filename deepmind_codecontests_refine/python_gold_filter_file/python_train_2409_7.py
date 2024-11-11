n = int(input())
a = list(map(int, input().split()))
mx = max(a); foo = 0
a = [-1] + a
a = a + [-1]
y = 0
for i in range(len(a)-1):
    if a[i]!=mx and a[i+1]==mx: y = i
    elif a[i]==mx and a[i+1]!=mx: foo = max(foo, i-y)
print(foo)
        
