a,b = -1e11,1e11
for _ in range(int(input())):
    c = int(input())
    a,b = max(a,c-b),min(b,c)
print(a)
