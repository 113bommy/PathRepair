N = int(input())
l = []
while N:
    N -= 1
    l.append(chr(97+(N % 26)))
    N //= 26

print("".join(l[::-1]))
