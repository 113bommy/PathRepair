s = input()
K = int(input())

for i in range(len(s)-1):
    z2a = (ord('z') + 1 - ord(s[i])) % 26
    if z2a <= K:
        s = s[:i] + 'a' + s[i+1:]
        K -= z2a

print(s[:len(s)-1] + chr(((ord(s[len(s)-1]) - ord('a')) + K % 26) % 26 + ord('a')))