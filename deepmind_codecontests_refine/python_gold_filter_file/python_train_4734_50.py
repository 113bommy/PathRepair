last = ''.join(input().split())
vowels = ['a', 'e', 'i', 'o', 'u', 'y']
if last[-2].lower() in vowels:
    print("YES")
else:
    print("NO")
