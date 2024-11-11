n = int(input())
a = [int(x) for x in input().split()]
sum = sum(a)
even, odd = 0, 0
for i in range(n):
    if(a[i] % 2 == 0): even += 1
    else: odd += 1
if(sum % 2 == 0): print(even)
else: print(odd)