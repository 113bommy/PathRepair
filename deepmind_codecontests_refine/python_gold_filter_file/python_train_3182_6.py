vowels = set(('a', 'e', 'i', 'o', 'u', 'y'))
n = int(input())
p = [int(_) for _ in input().split()]
for i in range(n):
    s = input()
    cnt = sum((1 if c in vowels else 0 for c in s))
    if cnt != p[i]:
        print('NO')
        exit(0)
print('YES')
    
