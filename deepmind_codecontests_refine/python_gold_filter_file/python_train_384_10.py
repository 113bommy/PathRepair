a = int(input())
b = list(map(int,input().split()))
b.sort()
sumo = sume = 0
for i in range(len(b)):
    sumo += abs(b[i] - 2*i - 1)
    sume += abs(b[i] - 2*(i+1))
print(min(sume,sumo))
