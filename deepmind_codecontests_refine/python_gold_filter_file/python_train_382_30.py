N = int(input())
R1, R2 = 0, 0
k = 1
for i in sorted(list(map(int,input().split()))):
    R1 += abs(k-i)
    R2 += abs(k+1-i)
    k += 2
print(min(R1,R2))
