S, Check = input(), [False] * 3
for i in S:
    if ord(i) in range(ord("A"), ord("Z") + 1): Check[0] = True
    if ord(i) in range(ord("a"), ord("z") + 1): Check[1] = True
    if ord(i) in range(ord("0"), ord("9") + 1): Check[2] = True
print("Correct" if len(S) >= 5 and Check.count(True) == 3 else "Too weak")

# Hope the best for Ravens
# Never give up
