N = int(input())
S = input()

ans = 0
for i in range(1000):
    target = str(i).zfill(3)
    char_idx = 0
    for c in S:
        if c == target[char_idx]:
            char_idx += 1

        if char_idx == 3:
            ans += 1
            break

print(ans)