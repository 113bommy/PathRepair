n = int(input())
s = list(input())
array = input().split() # Only maps 1-9
def f(c):
    # '1' is 49
    return array[ord(c) - 49]
i = 0
while i < len(s):
    if f(s[i]) > s[i]:
        while i < len(s) and f(s[i]) >= s[i]:
            s[i] = f(s[i])
            i += 1
        break
    i += 1
print (''.join(s))