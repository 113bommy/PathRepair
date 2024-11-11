n = input()
c = list(map(int, input().split()))
s = set()
answer = 0
c.sort(reverse=True)
for number in c:
    while number > 0:
        if number in s:
            number -= 1
        else:
            s.add(number)
            answer += number
            break
print(answer)
