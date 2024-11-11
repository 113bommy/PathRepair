N = int(input())
s = 0
for i in range(1,round(N**0.5)+1):
    if N % i == 0:
        s = i
print(s+N//s-2)