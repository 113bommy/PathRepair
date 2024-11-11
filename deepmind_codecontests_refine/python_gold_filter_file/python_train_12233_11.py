n = int(input())
i = 2
answer = 1

while i * i <= n:
    if n % i == 0:
        answer *= i
        while n % i == 0:
            n /= i
    i += 1

if n > 1:
    answer *= n

print(int(answer))