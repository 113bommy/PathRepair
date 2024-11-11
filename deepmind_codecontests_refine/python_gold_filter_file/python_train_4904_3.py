def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

n = int(input())


s1 = []
s2 = []
odd_sum = 0
even_sum = 0
for i in range(1, n+1):
    if i % 2:
        odd_sum += i
        s1.append(str(i))
    else:
        even_sum += i
        s2.append(str(i))

if gcd(odd_sum, even_sum) <= 1:
    print('No')
else:
    print('Yes')
    print(len(s1), ' '.join(s1))
    print(len(s2), ' '.join(s2))
