n = int(input())
s = input().split()
for i in range(n-1, -1, -1):
    if s[i] != s[n-1]:
        print(i+1)
        break
