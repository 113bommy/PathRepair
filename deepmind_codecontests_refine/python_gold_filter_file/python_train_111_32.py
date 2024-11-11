n = int(input())
a = list(map(int,input().split()))
k = 0

while k*len(a) - sum(a) <= sum(a):
    k += 1

if k < max(a):
    k = max(a)

print(k)
