n = int(input())
l = list(map(lambda x:int(x) - 1, input().split()))
l.sort()
a1 = 0
a2 = 0
for i in range(n//2):
    a1 += abs(i*2 - l[i])
    a2 += abs(i*2+1 - l[i])
print(min(a1, a2))
