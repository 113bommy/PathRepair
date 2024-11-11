n = int(input())
s = input()
t = input()
for i in range(n):
    if s[i:n] == t[0:n-i]:
        print(2*n - (n-i))
        exit()
print(2*n)
