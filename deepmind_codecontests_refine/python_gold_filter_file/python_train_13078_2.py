n = int(input())
lista = list(map(int, input().split(' ')))
ans = 1000
for i in range(0, n):
    sum = 0
    cont = i
    while cont < i + n:
        sum += lista[cont%n]
        ans = min(abs(sum - (360 - sum)), ans)
        cont += 1
print(ans)