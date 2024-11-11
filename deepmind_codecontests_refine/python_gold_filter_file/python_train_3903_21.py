n = input()
l = len(n)
s = 2**len(n) - 1

for i in range(l):
    if n[i] == '7':
        s += 2**(l-i-1)

print(s)
        
        
