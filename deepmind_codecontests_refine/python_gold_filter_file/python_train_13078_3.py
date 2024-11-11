n = int(input())
ai = list(map(int,input().split()))
ai2 = [0] * n
summ = sum(ai)
ai2[0] = ai[0]
minim = 360
for i in range(1,n):
    ai2[i] = ai2[i-1] +ai[i]
    minim = min(minim, abs(180 - ai2[i])*2)
for i in range(n-1,0,-1):
    for j in range(i):
        minim = min(minim,abs((180-(ai2[i]-ai2[j]))*2))
print(minim)
