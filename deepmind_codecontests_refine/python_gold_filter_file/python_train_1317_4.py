n = int(input())
s = input()
x = 1
for i in range(n//2, 0, -1):
    if (s[:i] == s[i:i*2]): 
        x = i
        break
print(n-(x-1))