n = input().split()
a = int(n[1])
b = int(n[2])
n = int(n[0])
x = list(map(int,input().split()))
x.sort()
res = x[b] - x[b-1]
print(res)