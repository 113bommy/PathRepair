n,m = map(int,input().split())
s = input()
t = input()
k = [-1]*1000

for i in range(m-n+1):
    x = t[i:i+n];
    temp = []
    for j in range(n):
        if x[j] != s[j]:
            temp.append(j)
    if len(temp) <= len(k):
        k = temp
print(len(k))
for i in k:
    print(i+1,end=' ')