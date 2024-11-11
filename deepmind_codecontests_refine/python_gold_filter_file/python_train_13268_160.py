n = int(input())
h = 0
for i in range(n):
    p,q = map(int,input().split())
    if (q-p)>1:
        h+=1
print(h)