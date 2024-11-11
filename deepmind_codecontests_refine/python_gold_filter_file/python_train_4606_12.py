a = int(input())
digits = []
for i in range(6):
    digits.append(a % 2)
    a //= 2
digits = digits[::-1]
digits_reordered = [digits[0], digits[5], digits[3], digits[2], digits[4], digits[1]]
answer = 0
for d in digits_reordered:
    answer = answer * 2 + d
print(answer)