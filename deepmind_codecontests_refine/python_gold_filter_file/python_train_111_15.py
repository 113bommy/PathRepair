a = int(input())
b = [int(i) for i in input().split()]
sum1 = sum2 = 0
kl = max(b)
for i in b:
    sum1 += i
    sum2 += (max(b)-i)
while(sum1>=sum2):
    sum2 += a
    kl += 1
print(kl)
