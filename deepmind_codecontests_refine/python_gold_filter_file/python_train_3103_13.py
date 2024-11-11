n = int(input())
l = list(map(int,input().split()))
a = []
for i in range(n):
    a.append(abs(sum(l[:i])-sum(l[i:])))
print(min(a))