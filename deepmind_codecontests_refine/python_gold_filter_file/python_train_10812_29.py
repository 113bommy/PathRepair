s = [ord(i) - 97 for i in input()]
k = int(input())

for i in range(len(s)):
    diff = 26 - s[i]
    if (s[i] != 0) and (diff <= k):
        k -= diff
        s[i] = 0

s[-1] = (s[-1] + k) % 26

ans = "".join(chr(i+97) for i in s)
print(ans)