n=int(input())
sum = 0
for i in range(n):
    x,u = input().split()
    sum += int(x) if u == 'JPY' else float(x) *380000
print(sum)