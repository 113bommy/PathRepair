b = int(input())
x = int(b**0.5)
answer = 0
for i in range(1,x+1):
    if b % i == 0:
        if i == b**0.5:
            answer += 1
        else:
            answer += 2
print(answer)
