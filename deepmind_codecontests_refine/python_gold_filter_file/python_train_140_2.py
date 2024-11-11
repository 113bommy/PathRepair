x = "abcdefghijklmnopqrstuvwxyz"
X = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
z = list(input())
n = int(input())
for i in range(len(z)):
    if(z[i] in x):
        k = x.index(z[i]) + 1
    else:
        k = X.index(z[i]) + 1
    if(k <= n):
        z[i] = z[i].upper()
    else:
        z[i] = z[i].lower()
ans = "".join(z)
print(ans)