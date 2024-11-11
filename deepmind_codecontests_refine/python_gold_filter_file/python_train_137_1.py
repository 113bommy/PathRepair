k = int(input())
s = sorted(input())
x = ''.join(s[::k]*k)
print((-1,x)[sorted(x) == s])

