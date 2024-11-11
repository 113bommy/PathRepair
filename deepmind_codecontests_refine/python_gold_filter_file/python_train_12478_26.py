N = int(input())

s = input()
t = input()

i = 0

while i < N:
    if s[i:] == t[:N-i]:
        break
    else:
        i+=1

print(N+i)